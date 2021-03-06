#include "OFPUnparser.hpp"
#include <assert.h>

void OFP::FortranTextUnparser::unparseNode(SgUntypedNode * node)
{
   if (!node) return;

   switch (node->variantT())
      {
         case V_SgUntypedFile:
            {
               SgUntypedFile * file = isSgUntypedFile(node);  assert(file);
               SgUntypedGlobalScope* scope = file->get_scope();

               SgUntypedDeclarationStatementPtrList programUnitList = scope->get_declaration_list()->get_decl_list();
               for (int i = 0; i < programUnitList.size(); i++) {
                  SgUntypedFunctionDeclaration * decl = isSgUntypedFunctionDeclaration(programUnitList.at(i));  assert(decl);
                  unparseDecl(decl);
               }
               break;
            }
         case V_SgUntypedProgramHeaderDeclaration:
            {
               SgUntypedProgramHeaderDeclaration * mp = isSgUntypedProgramHeaderDeclaration(node);  assert(mp);
               SgUntypedFunctionScope* scope = mp->get_scope();

               SgUntypedDeclarationStatementPtrList specList = scope->get_declaration_list()->get_decl_list();
               SgUntypedStatementPtrList            execList = scope->get_statement_list()->get_stmt_list();
               SgUntypedFunctionDeclarationPtrList  isubList = scope->get_function_list()->get_func_list();

               unparseDecl(mp);
               for (int i = 0; i < specList.size(); i++) {
                  SgUntypedDeclarationStatement * decl = isSgUntypedDeclarationStatement(specList.at(i));  assert(decl);
                  unparseDecl(decl);
               }
               for (int i = 0; i < execList.size(); i++) {
                  SgUntypedStatement * stmt = isSgUntypedStatement(execList.at(i));  assert(stmt);
                  unparseStmt(stmt);
               }
               //TODO for (int i = 0; i < subpList->size(); i++) {
               //TODO    SgUntypedStatement * stmt = dynamic_cast<SgUntypedStatement*>(subpList->at(i));  assert(stmt);
               //TODO    unparseStmt(stmt);
               //TODO }
               unparseStmt(mp->get_end_statement());
               break;
            }

         default:
            oss << "FortranTextUnparser::UnparseUnknownNode::::::::::::::::: " << node->variantT() << "\n";
      }
}

void OFP::FortranTextUnparser::unparseExpr(SgUntypedExpression * expr)
{
   if (!expr) return;

   switch (expr->variantT())
      {
        case V_SgUntypedReferenceExpression:
           {
              SgUntypedReferenceExpression * e = dynamic_cast<SgUntypedReferenceExpression*>(expr);
              if (e) {
                 oss << e->get_name();
              }
              break;
           }
        case V_SgUntypedValueExpression:
           {
              SgUntypedValueExpression * e = dynamic_cast<SgUntypedValueExpression*>(expr);
              if (e) {
                 oss << e->get_value_string();
                 if (e->get_type() && e->get_type()->get_has_kind()) {
                    // TODO kind should be an expression
                    oss << "_";
                    unparseExpr(e->get_type()->get_type_kind());
                 }
              }
              break;
           }
        case V_SgUntypedBinaryOperator:
           {
              SgUntypedBinaryOperator * binop = dynamic_cast<SgUntypedBinaryOperator*>(expr);
              if (binop) {
                 unparseExpr   (binop->get_lhs_operand());
                 unparseOpEnum (binop->get_operator_enum());
                 unparseExpr   (binop->get_rhs_operand());
              }
              break;
           }

        default:
           oss << "FortranTextUnparser::UnparseUnknownExpr:::::::::::::::::::::::: " << expr->variantT() << "\n";
      }
}

void OFP::FortranTextUnparser::unparseLabel(std::string label)
{
   if (label.length() > 0) {
      oss << label << " ";
   }
}

void OFP::FortranTextUnparser::unparseName(std::string name, std::string pre, std::string post)
{
   if (name.length() > 0) {
      oss << pre << name << post;
   }
}

void OFP::FortranTextUnparser::unparseOpEnum(SgToken::ROSE_Fortran_Operators e)
{
   switch (e)
      {
         case SgToken::FORTRAN_INTRINSIC_PLUS:    oss << " + ";      break;
         case SgToken::FORTRAN_INTRINSIC_MINUS:   oss << " - ";      break;
         case SgToken::FORTRAN_INTRINSIC_POWER:   oss << " ** ";     break;
         case SgToken::FORTRAN_INTRINSIC_CONCAT:  oss << " // ";     break;
         case SgToken::FORTRAN_INTRINSIC_TIMES:   oss << " * ";      break;
         case SgToken::FORTRAN_INTRINSIC_DIVIDE:  oss << " / ";      break;
         case SgToken::FORTRAN_INTRINSIC_AND:     oss << " .AND. ";  break;
         case SgToken::FORTRAN_INTRINSIC_OR:      oss << " .OR.  ";  break;
         case SgToken::FORTRAN_INTRINSIC_EQV:     oss << " .EQV. ";  break;
         case SgToken::FORTRAN_INTRINSIC_NEQV:    oss << " .NEQV. "; break;
         case SgToken::FORTRAN_INTRINSIC_EQ:      oss << " = ";      break;
         case SgToken::FORTRAN_INTRINSIC_NE:      oss << " /= ";     break;
         case SgToken::FORTRAN_INTRINSIC_GE:      oss << " >= ";     break;
         case SgToken::FORTRAN_INTRINSIC_LE:      oss << " <= ";     break;
         case SgToken::FORTRAN_INTRINSIC_LT:      oss << " < ";      break;
         case SgToken::FORTRAN_INTRINSIC_GT:      oss << " > ";      break;
         case SgToken::FORTRAN_INTRINSIC_NOT:     oss << " .NOT. ";  break;
         case SgToken::FORTRAN_INTRINSIC_OLDEQ:   oss << " .EQ. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDNE:   oss << " .NE. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDGE:   oss << " .GE. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDLE:   oss << " .LE. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDLT:   oss << " .LT. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDGT:   oss << " .GT. ";   break;
      }
}

void OFP::FortranTextUnparser::unparseStmt(SgUntypedStatement* stmt)
{
   if (!stmt) return;

   switch (stmt->variantT())
      {
        case V_SgUntypedAssignmentStatement:
           {
              SgUntypedAssignmentStatement * s = dynamic_cast<SgUntypedAssignmentStatement*>(stmt);
              if (s) {
                 unparseExpr(s->get_lhs_operand());
                 oss << " = ";
                 unparseExpr(s->get_rhs_operand());
                 oss << "\n";
              }
              break;
           }
        case V_SgUntypedNamedStatement:
           {
              SgUntypedNamedStatement * s = dynamic_cast<SgUntypedNamedStatement*>(stmt);
              if (s) {
                 unparseSgUntypedNamedStatement(s);
              }
              break;
           }

        default:
           oss << "FortranTextUnparser::UnparseUnknownStmt:::::::::::::::::::::::: " << stmt->variantT() << "\n";
      }
}


void OFP::FortranTextUnparser::unparseDecl(SgUntypedDeclarationStatement * decl)
{
   if (!decl) return;

   switch (decl->variantT())
      {
        case V_SgUntypedImplicitDeclaration:
           {
              SgUntypedStatement * s = dynamic_cast<SgUntypedStatement*>(decl);
              if (s) {
                 unparseLabel(s->get_label_string());
                 oss << "IMPLICIT";
                 if (s->get_statement_enum() == SgToken::FORTRAN_IMPLICIT_NONE) oss << " NONE";
                 else                                                           oss << " TODO";
                 oss << "\n";
              }
              break;
           }
        case V_SgUntypedSubroutineDeclaration:
           {
              SgUntypedSubroutineDeclaration * d = dynamic_cast<SgUntypedSubroutineDeclaration*>(decl);
              if (d) {
                 SgUntypedFunctionScope * scope = d->get_scope();
                 SgUntypedDeclarationList * declList = scope->get_declaration_list();
                 SgUntypedStatementList   * stmtList = scope->get_statement_list();
                 SgUntypedFunctionDeclarationList * funcList = scope->get_function_list();
                 
                 unparseLabel(d->get_label_string());
                 if (d->get_name().size() > 0) {
                    oss << "SUBROUTINE";
                    oss << " " << d->get_name();
                    oss << "\n";
                 }

                 for (int i = 0; i < declList->get_decl_list().size(); i++) {
                    unparseDecl(declList->get_decl_list().at(i));
                 }
                 for (int i = 0; i < stmtList->get_stmt_list().size(); i++) {
                    unparseStmt(stmtList->get_stmt_list().at(i));
                 }
                 for (int i = 0; i < funcList->get_func_list().size(); i++) {
                    //TODO-CER-2014.3.18 unparse funcList
                 }

                 unparseSgUntypedNamedStatement(d->get_end_statement());
              }
              break;
           }
        case V_SgUntypedProgramHeaderDeclaration:
           {
              SgUntypedProgramHeaderDeclaration * d = dynamic_cast<SgUntypedProgramHeaderDeclaration*>(decl);
              if (d) {
                 SgUntypedFunctionScope * scope = d->get_scope();
                 SgUntypedDeclarationList * declList = scope->get_declaration_list();
                 SgUntypedStatementList   * stmtList = scope->get_statement_list();
                 SgUntypedFunctionDeclarationList * funcList = scope->get_function_list();
                 
                 unparseLabel(d->get_label_string());
                 if (d->get_name().size() > 0) {
                    //TODO-DQ-2014.3.21 add has_program_statement member variable
                    oss << "PROGRAM";
                    oss << " " << d->get_name();
                    oss << "\n";
                 }

                 for (int i = 0; i < declList->get_decl_list().size(); i++) {
                    unparseDecl(declList->get_decl_list().at(i));
                 }
                 for (int i = 0; i < stmtList->get_stmt_list().size(); i++) {
                    unparseStmt(stmtList->get_stmt_list().at(i));
                 }
                 for (int i = 0; i < funcList->get_func_list().size(); i++) {
                    //TODO-CER-2014.3.18 unparse funcList
                 }

                 unparseSgUntypedNamedStatement(d->get_end_statement());
              }
              break;
           }
        case V_SgUntypedVariableDeclaration:
           {
              SgUntypedVariableDeclaration * d = dynamic_cast<SgUntypedVariableDeclaration*>(decl);
              if (d) {
                 SgUntypedInitializedNamePtrList names = d->get_parameters()->get_name_list();
                 assert(names.size() > 0);
                 oss << names.at(0)->get_type()->get_type_name() << " ";
                 for (int i = 0; i < names.size(); i++) {
                    oss << names.at(i)->get_name();
                    if (i < names.size() - 1) oss << ", ";
                 }
                 oss << "\n";
              }
              break;
           }

        default:
           oss << "FortranTextUnparser::UnparseUnknownDecl::::::::::::::::::::::::" << decl->variantT() << "\n";
      }
}


void OFP::FortranTextUnparser::unparseSgUntypedNamedStatement(SgUntypedNamedStatement* stmt)
{
   if (!stmt) return;

   switch (stmt->get_statement_enum())
      {
        case SgToken::FORTRAN_END_PROGRAM:
           {
              unparseLabel(stmt->get_label_string());
              oss << "END PROGRAM ";
              oss << stmt->get_statement_name();
              oss << "\n";
              break;
           }
        case SgToken::FORTRAN_END_SUBROUTINE:
           {
              unparseLabel(stmt->get_label_string());
              oss << "END SUBROUTINE ";
              oss << stmt->get_statement_name();
              oss << "\n";
              break;
           }

        default:
           oss << "FortranTextUnparser::UnparseSgUntypedNamedStatement:::::::::::::::::::::::: " << stmt->get_statement_enum() << "\n";
      }
}

