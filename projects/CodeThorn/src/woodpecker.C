// Author: Markus Schordan, 2013.

#include "rose.h"

#include "inliner.h"

#include <iostream>
#include "VariableIdMapping.h"
#include "Labeler.h"
#include "CFAnalyzer.h"
#include "RDLattice.h"
#include "DFAnalyzer.h"
#include "WorkList.h"
#include "RDAnalyzer.h"
#include "RDAstAttribute.h"
#include "AstAnnotator.h"
#include "DataDependenceVisualizer.h"
#include "Miscellaneous.h"
#include "ProgramStats.h"
#include "CommandLineOptions.h"
#include "AnalysisAbstractionLayer.h"
#include "AType.h"
#include "SgNodeHelper.h"
#include "FIConstAnalysis.h"
#include "TrivialInlining.h"

#include <vector>
#include <set>
#include <list>
#include <string>

#include "limits.h"
#include <cmath>
#include "assert.h"

using namespace std;
using namespace CodeThorn;
using namespace AType;

#include "ReachabilityResults.h"
#include "DeadCodeElimination.h"
#include "ReachabilityAnalysis.h"

//static  VariableIdSet variablesOfInterest;
static bool detailedOutput=0;
const char* csvAssertFileName=0;
const char* csvConstResultFileName=0;
bool global_option_multiconstanalysis=false;

// temporary
//#include "ReachabilityAnalysis.C"

#if 0
bool isVariableOfInterest(VariableId varId) {
  return variablesOfInterest.find(varId)!=variablesOfInterest.end();
}
#endif

size_t numberOfFunctions(SgNode* node) {
  RoseAst ast(node);
  size_t num=0;
  for(RoseAst::iterator i=ast.begin();i!=ast.end();i++) {
    if(isSgFunctionDefinition(*i))
      num++;
  }
  return num;
}

//#include "FIConstAnalysis.C"
//#include "DeadCodeEliminationOperators.C"


void printResult(VariableIdMapping& variableIdMapping, VarConstSetMap& map) {
  cout<<"Result:"<<endl;
  VariableConstInfo vci(&variableIdMapping, &map);
  for(VarConstSetMap::iterator i=map.begin();i!=map.end();++i) {
    VariableId varId=(*i).first;
    //string variableName=variableIdMapping.uniqueShortVariableName(varId);
    string variableName=variableIdMapping.variableName(varId);
    set<CppCapsuleConstIntLattice> valueSet=(*i).second;
    stringstream setstr;
    setstr<<"{";
    for(set<CppCapsuleConstIntLattice>::iterator i=valueSet.begin();i!=valueSet.end();++i) {
      if(i!=valueSet.begin())
        setstr<<",";
      setstr<<(*i).getValue().toString();
    }
    setstr<<"}";
    cout<<variableName<<"="<<setstr.str()<<";";
#if 1
    cout<<"Range:"<<VariableConstInfo::createVariableValueRangeInfo(varId,map).toString();
    cout<<" width: "<<VariableConstInfo::createVariableValueRangeInfo(varId,map).width().toString();
    cout<<" top: "<<VariableConstInfo::createVariableValueRangeInfo(varId,map).isTop();
    cout<<endl;
#endif
    cout<<" isAny:"<<vci.isAny(varId)
        <<" isUniqueConst:"<<vci.isUniqueConst(varId)
        <<" isMultiConst:"<<vci.isMultiConst(varId);
    if(vci.isUniqueConst(varId)||vci.isMultiConst(varId)) {
      cout<<" width:"<<vci.width(varId);
    } else {
      cout<<" width:unknown";
    }
    cout<<" Test34:"<<vci.isInConstSet(varId,34);
    cout<<endl;
  }
  cout<<"---------------------"<<endl;
}


void printCodeStatistics(SgNode* root) {
  SgProject* project=isSgProject(root);
  VariableIdMapping variableIdMapping;
  variableIdMapping.computeVariableSymbolMapping(project);
  VariableIdSet setOfUsedVars=AnalysisAbstractionLayer::usedVariablesInsideFunctions(project,&variableIdMapping);
  DeadCodeElimination dce;
  cout<<"----------------------------------------------------------------------"<<endl;
  cout<<"Statistics:"<<endl;
  cout<<"Number of empty if-statements: "<<dce.listOfEmptyIfStmts(root).size()<<endl;
  cout<<"Number of functions          : "<<SgNodeHelper::listOfFunctionDefinitions(project).size()<<endl;
  cout<<"Number of global variables   : "<<SgNodeHelper::listOfGlobalVars(project).size()<<endl;
  cout<<"Number of used variables     : "<<setOfUsedVars.size()<<endl;
  cout<<"----------------------------------------------------------------------"<<endl;
  cout<<"VariableIdMapping-size       : "<<variableIdMapping.getVariableIdSet().size()<<endl;
  cout<<"----------------------------------------------------------------------"<<endl;
}


int main(int argc, char* argv[]) {
  try {
    if(argc==1) {
      cout << "Error: wrong command line options."<<endl;
      exit(1);
    }
#if 0
    if(argc==3) {
      csvAssertFileName=argv[2];
      argc=2; // don't confuse ROSE command line
      cout<< "INIT: CSV-output file: "<<csvAssertFileName<<endl;
    }
#endif
  // Command line option handling.
    namespace po = boost::program_options;
  po::options_description desc
    ("Woodpecker V0.1\n"
     "Written by Markus Schordan\n"
     "Supported options");
  
  desc.add_options()
    ("help,h", "produce this help message.")
    ("rose-help", "show help for compiler frontend options.")
    ("version,v", "display the version.")
    ("stats", "display code statistics.")
    ("inline",po::value< string >(), "perform inlining ([yes]|no).")
    ("eliminate-empty-if",po::value< string >(), "eliminate if-statements with empty branches in main function ([yes]/no).")
    ("eliminate-dead-code",po::value< string >(), "eliminate dead code (variables and expressions) ([yes]|no).")
    ("csv-const-result",po::value< string >(), "generate csv-file [arg] with const-analysis data.")
    ("generate-transformed-code",po::value< string >(), "generate transformed code with prefix rose_ ([yes]|no).")
    ("verbose",po::value< string >(), "print detailed output during analysis and transformation (yes|[no]).")
    ("csv-assert",po::value< string >(), "name of csv file with reachability assert results'")
    ("enable-multi-const-analysis",po::value< string >(), "enable multi-const analysis.")
    ;
  //    ("int-option",po::value< int >(),"option info")


  po::store(po::command_line_parser(argc, argv).
            options(desc).allow_unregistered().run(), args);
  po::notify(args);

  if (args.count("help")) {
    cout << "woodpecker <filename> [OPTIONS]"<<endl;
    cout << desc << "\n";
    return 0;
  }
  if (args.count("rose-help")) {
    argv[1] = strdup("--help");
  }

  if (args.count("version")) {
    cout << "Woodpecker version 0.1\n";
    cout << "Written by Markus Schordan 2013\n";
    return 0;
  }
  if (args.count("csv-assert")) {
    csvAssertFileName=args["csv-assert"].as<string>().c_str();
  }
  if (args.count("csv-const-result")) {
    csvConstResultFileName=args["csv-const-result"].as<string>().c_str();
  }
  
  
  boolOptions.init(argc,argv);
  // temporary fake optinos
  boolOptions.registerOption("arith-top",false); // temporary
  boolOptions.registerOption("semantic-fold",false); // temporary
  boolOptions.registerOption("post-semantic-fold",false); // temporary
  // regular options
  boolOptions.registerOption("inline",true);
  boolOptions.registerOption("eliminate-empty-if",true);
  boolOptions.registerOption("eliminate-dead-code",true);
  boolOptions.registerOption("generate-transformed-code",true);
  boolOptions.registerOption("enable-multi-const-analysis",false);
  boolOptions.registerOption("verbose",false);
  boolOptions.processOptions();

  if(boolOptions["verbose"])
    detailedOutput=1;

  // clean up string-options in argv
  for (int i=1; i<argc; ++i) {
    if (string(argv[i]) == "--csv-assert" 
        || string(argv[i]) == "--csv-const-result"
        ) {
      // do not confuse ROSE frontend
      argv[i] = strdup("");
      assert(i+1<argc);
        argv[i+1] = strdup("");
    }
  }

  global_option_multiconstanalysis=boolOptions["enable-multi-const-analysis"];
#if 0
  if(global_option_multiconstanalysis) {
    cout<<"INFO: Using flow-insensitive multi-const-analysis."<<endl;
  } else {
    cout<<"INFO: Using flow-insensitive unique-const-analysis."<<endl;
  }
#endif

  cout << "INIT: Parsing and creating AST."<<endl;
  SgProject* root = frontend(argc,argv);
  //  AstTests::runAllTests(root);
  // inline all functions

  if(args.count("stats")) {
    printCodeStatistics(root);
    exit(0);
  }

  SgFunctionDefinition* mainFunctionRoot=0;
  if(boolOptions["inline"]) {
    // inline functions
    TrivialInlining tin;
    tin.setDetailedOutput(true);
    tin.inlineFunctions(root);
    DeadCodeElimination dce;
    // eliminate non called functions
    int numEliminatedFunctions=dce.eliminateNonCalledTrivialFunctions(root);
    cout<<"STATUS: eliminated "<<numEliminatedFunctions<<" functions."<<endl;
  } else {
    cout<<"INFO: Inlining: turned off."<<endl;
  }

  if(boolOptions["inline"]) {
  }
  
  if(boolOptions["eliminate-empty-if"]) {
    DeadCodeElimination dce;
    cout<<"STATUS: Eliminating empty if-statements."<<endl;
    size_t num=0;
    size_t numTotal=num;
    do {
      num=dce.eliminateEmptyIfStmts(root);
      cout<<"INFO: Number of if-statements eliminated: "<<num<<endl;
      numTotal+=num;
    } while(num>0);
    cout<<"STATUS: Total number of empty if-statements eliminated: "<<numTotal<<endl;
  }
  
  cout<<"STATUS: performing flow-insensitive const analysis."<<endl;
  VariableIdMapping variableIdMapping;
  variableIdMapping.computeVariableSymbolMapping(root);

  VarConstSetMap varConstSetMap;
  VariableIdSet variablesOfInterest;
  FIConstAnalysis fiConstAnalysis(&variableIdMapping);
  fiConstAnalysis.setOptionMultiConstAnalysis(global_option_multiconstanalysis);
  fiConstAnalysis.runAnalysis(root, mainFunctionRoot);
  variablesOfInterest=fiConstAnalysis.determinedConstantVariables();
  cout<<"INFO: variables of interest: "<<variablesOfInterest.size()<<endl;
  if(detailedOutput)
    printResult(variableIdMapping,varConstSetMap);

  if(csvConstResultFileName) {
    fiConstAnalysis.writeCvsConstResult(variableIdMapping, string(csvConstResultFileName));
  }

  VariableConstInfo vci=*(fiConstAnalysis.getVariableConstInfo());
  DeadCodeElimination dce;
  if(boolOptions["eliminate-dead-code"]) {
    cout<<"STATUS: performing dead code elimination."<<endl;
    dce.setDetailedOutput(false);
    dce.setVariablesOfInterest(variablesOfInterest);
    dce.eliminateDeadCodePhase1(root,&variableIdMapping,vci);
    cout<<"STATUS: Eliminated "<<dce.numElimVars()<<" variable declarations."<<endl;
    cout<<"STATUS: Eliminated "<<dce.numElimAssignments()<<" variable assignments."<<endl;
    cout<<"STATUS: Replaced "<<dce.numElimVarUses()<<" uses of variables with constant."<<endl;
    cout<<"STATUS: Eliminated "<<dce.numElimVars()<<" dead variables."<<endl;
    cout<<"STATUS: Dead code elimination phase 1: finished."<<endl;
    cout<<"STATUS: Performing condition const analysis."<<endl;
  } else {
    cout<<"STATUS: Dead code elimination: turned off."<<endl;
  }
  if(csvAssertFileName) {
    cout<<"STATUS: performing flow-insensensitive condition-const analysis."<<endl;
    Labeler labeler(root);
    fiConstAnalysis.performConditionConstAnalysis(&labeler);
    cout<<"INFO: Number of true-conditions     : "<<fiConstAnalysis.getTrueConditions().size()<<endl;
    cout<<"INFO: Number of false-conditions    : "<<fiConstAnalysis.getFalseConditions().size()<<endl;
    cout<<"INFO: Number of non-const-conditions: "<<fiConstAnalysis.getNonConstConditions().size()<<endl;
    cout<<"STATUS: performing flow-insensensitive reachability analysis."<<endl;
    ReachabilityAnalysis ra;
    ReachabilityResults reachabilityResults=ra.fiReachabilityAnalysis(labeler, fiConstAnalysis);
    cout<<"STATUS: generating file "<<csvAssertFileName<<endl;
    reachabilityResults.write2013File(csvAssertFileName,true);
  }
#if 0
  rdAnalyzer->determineExtremalLabels(startFunRoot);
  rdAnalyzer->run();
#endif
  cout << "INFO: Remaining functions in program: "<<numberOfFunctions(root)<<endl;
  if(boolOptions["generate-transformed-code"]) {
    cout << "STATUS: generating transformed source code."<<endl;
    root->unparse(0,0);
  }

  cout<< "STATUS: finished."<<endl;

  // main function try-catch
  } catch(char* str) {
    cerr << "*Exception raised: " << str << endl;
    return 1;
  } catch(const char* str) {
    cerr << "Exception raised: " << str << endl;
    return 1;
  } catch(string str) {
    cerr << "Exception raised: " << str << endl;
    return 1;
  }
  return 0;
}
