/*
* Author: M1043833 ( Srinivasan Rajendran )
* Description: This file (File1.h) contains contains prototype for file1.cpp
*
* */

#ifndef __FILE1_H__
#define __FILE1_H__


#ifdef WIN32
#ifdef LIBRARY1_EXPORTS
#define LIBRARY_API __declspec(dllexport) 
#else
#define LIBRARY_API __declspec(dllimport) __stdcall
#endif
#else
#define LIBRARY_API
#endif

extern "C" void LIBRARY_API Func1();
extern "C" void LIBRARY_API Func2();
#endif
