#ifndef MAIN_HPP
#define MAIN_HPP

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <mutex>

//Debug mode, default on
#ifndef NO_DEBUG

  //Useful for debugging
  #include <iostream>
  #include <libgen.h>

  //A macro that prints the line, file, and function, useful in debugging
  #define DBG std::cerr << basename((char*)__FILE__) << ": " << __LINE__ \
                        << " - "<< __PRETTY_FUNCTION__ << std::endl;

#endif

//A simple macro that prevents the function
//it is in from running multiple times, thread safe
#define RUN_ONCE {                      \
    static bool neverRun = true;        \
    static std::mutex m; m.lock();      \
    std::string s(__PRETTY_FUNCTION__); \
    s += "() should only run once!";    \
    Assert(neverRun, s.c_str());        \
    neverRun = false;                   \
    m.unlock();                         \
}

//Used for error checking
void Err(const char * s);
void Assert(bool b, const char * s);

#endif
