#ifndef BASE_H
#define BASE_H

//////////////////
// NOTE: Context Cracking


#if defined(__clang__)
# define COMPILER_CLANG 1
# if defined (__gnu_linux__)
#  define OS_LINUX 1
# elif defined(__APPLE__) && defined(__MACH__)
#  define OS_MAC 1
# elif defined(_WIN32)
#  define OS_WINDOWS 1
# else
#  error missing OS detection
# endif 
#elif defined(__GNUC__)
# define COMPILER_GCC 1
# if defined (__gnu_linux__)
#  define OS_LINUX 1
# elif defined(__APPLE__) && defined(__MACH__)
#  define OS_MAC 1
# elif defined(_WIN32)
#  define OS_WINDOWS 1
# else
#  error missing OS detection
# endif 
#else
# error no context cracking for this compiler 
#endif // __clang__

// NOTE: Zero fill missing context macros

#if !defined(COMPILER_CLANG)
# define COMPILER_CLANG 0
#endif // COMPILER_CLANG
#if !defined(COMPILER_GCC)
# define COMPILER_GCC 0
#endif // COMPILER_GCC
#if !defined(OS_LINUX)
# define OS_LINUX 0
#endif // OS_LINUX
#if !defined(OS_MAC)
# define OS_MAC 0
#endif // OS_MAC
#if !defined(OS_WINDOWS)
# define OS_WINDOWS 0
#endif

//////////////////
// NOTE: Helper macros

#define global static
#define local static
#define function static


//////////////////
// NOTE: Basic types

#include<stdint.h>
typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;
typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef S8 B8;
typedef S16 B16;
typedef S32 B32;
typedef S64 B64;
typedef float F32;
typedef double F64;

//////////////////
// NOTE: Basic constants

global S8  min_S8  = (S8)  0x80;
global S16 min_S16 = (S16) 0x8000;
global S32 min_S32 = (S32) 0x80000000;
global S64 min_S64 = (S64) 0x8000000000000000llu;

global S8  max_S8  = (S8)  0x7f;
global S16 max_S16 = (S16) 0x7fff;
global S32 max_S32 = (S32) 0x7fffffff;
global S64 max_S64 = (S64) 0x7fffffffffffffffllu;

global U8 max_U8 = 0xff;
global U16 max_U16 = 0xffff;
global U32 max_U32 = 0xffffffff;
global U64 max_U64 = 0xffffffffffffffffllu;
#endif // BASE_H
