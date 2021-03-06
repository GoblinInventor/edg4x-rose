#ifndef __JAVA_JSERVER_H__
#define __JAVA_JSERVER_H__

#include "jni.h"

#define STATIC_METHOD 1
#define REGULAR_METHOD 0

#define xDEBUG(flag,code)  { if(flag) {code; fflush(stdout);}}

class SgClassDefinition;
class SgClassType;
class SgClassType;
class SgClassType;
class SgVariableSymbol;
class SgProject;

namespace Rose {
    namespace Frontend {
        namespace Java {

            extern SgClassDefinition *javaLangPackageDefinition;
            extern SgClassType *ObjectClassType;
            extern SgClassType *StringClassType;
            extern SgClassType *ClassClassType;
            extern SgVariableSymbol *lengthSymbol;

            namespace Ecj {

                extern SgProject* Ecj_globalProjectPointer;
                jstring      jserver_getJavaString(const char*);
                jobject      jserver_getNewObject(jclass,jmethodID, jobjectArray,jstring,jstring);
                jclass       jserver_FindClass(const char *name);
                jobjectArray jserver_getJavaStringArray(int argc, char **argv);
                void         jserver_callMethod(jclass, jmethodID, jobjectArray);
                int          jserver_callBooleanMethod(jobject, jmethodID);
                jmethodID    jserver_GetMethodID(int, jclass, const char*, const char*);
                void         jserver_handleException();
                void         jserver_init();
                void         jserver_finish();
                JNIEnv* getEnv();

                extern jclass currentJavaTraversalClass;
                extern JNIEnv *currentEnvironment;
                extern jmethodID mainMethod;
                extern jmethodID hasConflictsMethod;
                extern jmethodID getTempDirectoryMethod;
                extern jmethodID createTempFileMethod;
                extern jmethodID createTempNamedFileMethod;
                extern jmethodID createTempNamedDirectoryMethod;

            }// Rose::Frontend::Java::Ecj
        }// Rose::Frontend::Java
    }// Rose::Frontend
}// Rose

#endif
