#ifndef BASE_H
#define BASE_H

// NOTE: Basic type renaming
#include <cstdint>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef float f32;
typedef double f64;

// NOTE: Constants
const s8 min_s8 = (s8)0x80;
const s16 min_s16 = (s16)0x8000;
const s32 min_s32 = (s32)0x80000000;
const s64 min_s64 = (s64)0x8000000000000000LL;

const s8 max_s8 = (s8)0x7f;
const s16 max_s16 = (s16)0x7fff;
const s32 max_s32 = (s32)0x7fffffff;
const s64 max_s64 = (s64)0x7fffffffffffffffLL;

const u8 max_u8 = (u8)0xff;
const u16 max_u16 = (u16)0xffff;
const u32 max_u32 = (u32)0xffffffff;
const u64 max_u64 = (u64)0xffffffffffffffffULL;

// NOTE: Platform cracking
#if defined(__linux__)
#define IS_LINUX 1
#else
#define IS_LINUX 0
#endif

#if defined(_WIN32)
#define IS_WINDOWS 1
#else
#define IS_WINDOWS 0
#endif

#if defined(__APPLE__) && defined(__MACH__)
#define IS_MACOS 1
#else
#define IS_MACOS 0
#endif

// NOTE: Error Handling
#define SUCCESS 0
#define FAILURE -1

// NOTE: Utility macros
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define UNUSED(x) (void)(x)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// NOTE: Debugging Macros
#include <stdio.h>
#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...)                                                  \
  do {                                                                         \
    fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, __FILE__, __LINE__, __func__,   \
            __VA_ARGS__);                                                      \
  } while (0)
#else
#define DEBUG_PRINT(fmt, ...)                                                  \
  do {                                                                         \
  } while (0)
#endif

#endif // BASE_H
