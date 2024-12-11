#pragma once

#include "Substance/Core/CoreCompiler.h"

// []===================================================================[]
// The macro ST_LIBRARY_SHARED is a user defined macro that is used
// to determine if the library is being built as a shared library or as
// a static library. If it is defined the LIBRARY_API macro will be set
// to DLL_EXPORT if ST_COMPILE_LIBRARY is defined, otherwise it will
// be set to DLL_IMPORT. If ST_LIBRARY_SHARED is not defined, the
// LIBRARY_API macro will be set to nothing.
// []===================================================================[]
#ifdef ST_LIBRARY_SHARED
#	ifdef ST_COMPILE_LIBRARY
#		define LIBRARY_API DLL_EXPORT
#	else
		#define LIBRARY_API DLL_IMPORT
#	endif
#else
#	define LIBRARY_API
#endif
