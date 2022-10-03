#pragma once
#ifdef _DEBUG
//#include <vld.h> /* Visual Leak Detector Memory Leak Detection*/
#include <crtdbg.h> /*VS Memory Leak Detection*/
#include <stack>
#include <memory>
#include <sstream>
#include "Windows.h"

class MemoryLeakDetector {
 public:
  MemoryLeakDetector() {};
  _CrtMemState MEMORYLEAKSTATISTICS1;
  _CrtMemState MEMORYLEAKSTATISTICS2;
  _CrtMemState MEMORYLEAKSTATISTICS3;
  static std::stack<std::unique_ptr<MemoryLeakDetector>>& stack() {
    static std::stack<std::unique_ptr<MemoryLeakDetector>> s;
    return s;
  }
};


#define DBOUT( s )                              \
do{                                         \
   std::ostringstream os;                   \
   os << s;                                 \
   OutputDebugString(os.str().c_str() );    \
}while(0)

#define BEGINMEMORYLEAKCHECK() do{std::unique_ptr<MemoryLeakDetector> ___memoryleakdetector___ = std::make_unique<MemoryLeakDetector>();\
                                MemoryLeakDetector::stack().push(std::move(___memoryleakdetector___));\
                                _CrtMemCheckpoint(&MemoryLeakDetector::stack().top().get()->MEMORYLEAKSTATISTICS1);\
                                }while(0)
#define ENDMEMORYLEAKCHECK() do{if(MemoryLeakDetector::stack().size()==0){DBOUT("\n"<<__FILE__<<"("<<__LINE__<<"):"<<"<"<<__FUNCTION__<<" ENDMEMORYLEAKCHECK without BEGINMEMORYLEAKCHECK detected\n");\
                            break;}\
                            std::unique_ptr<MemoryLeakDetector> ___memoryleakdetector___ = std::move(MemoryLeakDetector::stack().top());MemoryLeakDetector::stack().pop();\
                            _CrtMemCheckpoint(&___memoryleakdetector___->MEMORYLEAKSTATISTICS2);\
                            if (_CrtMemDifference(&___memoryleakdetector___->MEMORYLEAKSTATISTICS3, &___memoryleakdetector___->MEMORYLEAKSTATISTICS1, &___memoryleakdetector___->MEMORYLEAKSTATISTICS2)){\
                            DBOUT("\n"<<__FILE__<<"("<<__LINE__<<"):"<<"<"<<__FUNCTION__<<"> MLD detected a leak\n");\
                            _CrtMemDumpStatistics(&___memoryleakdetector___->MEMORYLEAKSTATISTICS3);\
                            DBOUT("\n\n");\
                            std::cerr << "MLD Leak detected "<<__FILE__<<"("<<__LINE__<<")"<< std::endl;\
                            }}while(0)
#else
#define BEGINMEMORYLEAKCHECK() do{}while(0)
    #define ENDMEMORYLEAKCHECK() do{}while(0)
    #define DBOUT( s )  do{}while(0)
#endif

#include <iostream>
using namespace std;
int main() {
  setlocale(LC_ALL, "eng");

  BEGINMEMORYLEAKCHECK();
  long *ms = new long[2]; //MEM Leak
  ENDMEMORYLEAKCHECK();

  //---------------------------------------------

  BEGINMEMORYLEAKCHECK();
  long *ms1 = new long[2]; //No Leak
  delete ms1;
  ENDMEMORYLEAKCHECK();
  return 0;
}
