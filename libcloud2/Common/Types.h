#ifndef __TYPES_H__

#include <string>
#include <iostream>
#include <vector>
#include "Timer.h"

typedef signed char SInt8;
typedef signed short int SInt16;
typedef signed int SInt32;
typedef signed long long int SInt64;

typedef unsigned char UInt8;
typedef unsigned short int UInt16;
typedef unsigned int UInt32;
typedef unsigned long long int UInt64;

typedef float Float32;
typedef double Float64;

typedef bool Boolean;

typedef std::vector <UInt32> Indices;

#if 1
#define ERROR(text) throw std::string (__PRETTY_FUNCTION__) + ": " + text;
#define PRINT(val) std::cout << "DEBUG (" << __PRETTY_FUNCTION__ << "): " << #val << ": " << val << std::endl;
#define DEBUG(text) std::cout << "DEBUG (" << __PRETTY_FUNCTION__ << "): " << text << std::endl;
#define TIMER(code) Timer t; code; DEBUG("executing " << #code << " tooks " << t.getElapsed () << " seconds");
#define ASSERT(expression,message) if (!(expression)) ERROR (message);
#else
#define ERROR(text)
#define PRINT(val)
#define DEBUG(text)
#define TIMER(code) code;
#define ASSERT(expression,message)
#endif
#endif