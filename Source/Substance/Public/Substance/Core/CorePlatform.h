#pragma once

// []===================================================================[]
// Available platform definitions:
// []===================================================================[]

#if defined(__linux) || defined(__linux__)
#	define ST_PLATFORM_LINUX 1
#	define ST_PLATFORM_NAME "Linux"
#	ifdef __x86_64__
#		define ST_PLATFORM_X64 1
#		define ST_PLATFORM_X32 0
#	else
#		define ST_PLATFORM_X64 0
#		define ST_PLATFORM_X32 1
#	endif
#elif defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
#	define ST_PLATFORM_WINDOWS 1
#	define ST_PLATFORM_NAME "Windows"
#	ifdef _WIN64
#		define ST_PLATFORM_X64 1
#		define ST_PLATFORM_X32 0
#	else
#		define ST_PLATFORM_X64 0
#		define ST_PLATFORM_X32 1
#	endif
#endif

#ifndef ST_PLATFORM_LINUX
#	define ST_PLATFORM_LINUX 0
#endif

#ifndef ST_PLATFORM_WINDOWS
#	define ST_PLATFORM_WINDOWS 0
#endif

#ifdef __WORDSIZE
#	define ST_POINTER_SIZE (__WORDSIZE / 8)
#elif ST_PLATFORM_X64
#	define ST_POINTER_SIZE 8
#else
#	define ST_POINTER_SIZE 4
#endif

#define ST_PLATFORM_POINTER_ALIGNMENT (ST_POINTER_SIZE * 2)
