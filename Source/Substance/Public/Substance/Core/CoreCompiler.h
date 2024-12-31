#pragma once
// ReSharper disable CppClangTidyModernizeMacroToEnum

// []===================================================================[]
// // User definable macros:
// - ST_REQUIRED_CPP_VERSION (Minimum required C++ version)
// []===================================================================[]
// Available compiler definitions:
// - ST_COMPILER_CLANG
// - ST_COMPILER_GCC
// - ST_COMPILER_MSVC
// - ST_COMPILER_UNKNOWN
//
// Additional compiler definitions:
// - ST_COMPILER_VERSION_MAJOR
// - ST_COMPILER_VERSION_MINOR
// - ST_COMPILER_VERSION_PATCH
// - ST_COMPILER_NAME
//
// Available C++ versions:
// - ST_CPP_VERSION11
// - ST_CPP_VERSION14
// - ST_CPP_VERSION17
// - ST_CPP_VERSION20
// - ST_CPP_VERSION23
// - ST_CPP_VERSION (Current C++ version)
//
// Available attributes:
// - NODISCARD
// - NORETURN
// - MAYBE_UNUSED
// - LIKELY
// - UNLIKELY
// - DEPRECATED
// - DEPRECATED_MSG(Message)
//
// Available compiler specifics:
// - FORCEINLINE
// - NOINLINE
// - DLL_EXPORT
// - DLL_IMPORT
// []===================================================================[]

#pragma region Compiler
#	if defined(__clang__) && !defined(_MSC_VER)
#		define ST_COMPILER_CLANG 1
#		define ST_COMPILER_VERSION_MAJOR __clang_major__
#		define ST_COMPILER_VERSION_MINOR __clang_minor__
#		define ST_COMPILER_VERSION_PATCH __clang_patchlevel__
#		define ST_COMPILER_NAME "Clang"
#	elif defined(__GNUC__)
#		define ST_COMPILER_GCC 1
#		define ST_COMPILER_VERSION_MAJOR __GNUC__
#		define ST_COMPILER_VERSION_MINOR __GNUC_MINOR__
#		define ST_COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__
#		define ST_COMPILER_NAME "GCC"
#	elif defined(_MSC_VER)
#		define ST_COMPILER_MSVC 1
#		define ST_COMPILER_VERSION_MAJOR _MSC_VER
#		define ST_COMPILER_VERSION_MINOR 0
#		define ST_COMPILER_VERSION_PATCH 0
#		define ST_COMPILER_NAME "MSVC"
#	else
#		define ST_COMPILER_UNKNOWN 1
#		define ST_COMPILER_VERSION_MAJOR 0
#		define ST_COMPILER_VERSION_MINOR 0
#		define ST_COMPILER_VERSION_PATCH 0
#		define ST_COMPILER_NAME "Unknown"
#	endif

#	ifndef ST_COMPILER_CLANG
#		define ST_COMPILER_CLANG 0
#	endif

#	ifndef ST_COMPILER_GCC
#		define ST_COMPILER_GCC 0
#	endif

#	ifndef ST_COMPILER_MSVC
#		define ST_COMPILER_MSVC 0
#	endif

#	ifndef ST_COMPILER_UNKNOWN
#		define ST_COMPILER_UNKNOWN 0
#	endif

#	if ST_COMPILER_UNKNOWN
#		error "Unknown compiler"
#	endif
#pragma endregion // Compiler

#pragma region CPP
#	define ST_CPP_VERSION11 201103L
#	define ST_CPP_VERSION14 201402L
#	define ST_CPP_VERSION17 201703L
#	define ST_CPP_VERSION20 202002L
#	define ST_CPP_VERSION23 202302L

#	if ST_COMPILER_MSVC
#		define ST_CPP_VERSION _MSVC_LANG
#	elif defined(__cplusplus)
#		define ST_CPP_VERSION __cplusplus
#	else
#		define ST_CPP_VERSION 0
#	endif

#	if !ST_CPP_VERSION
#		error "A c++ compatible compiler is required"
#	endif

#	ifdef ST_REQUIRED_CPP_VERSION
#		if ST_CPP_VERSION < ST_REQUIRED_CPP_VERSION
#			error "C++ version not supported"
#		endif
#	endif
#pragma endregion // CPP

#pragma region VersionSpecifics
#	if ST_CPP_VERSION >= ST_CPP_VERSION11
#		define STATIC_ASSERT(Condition, Message) static_assert(Condition, Message)
#		define CONSTEXPR constexpr
#	else
#		define STATIC_ASSERT(Condition, Message)
#		define CONSTEXPR
#	endif
#pragma endregion

#pragma region Attributes
#	ifdef __has_cpp_attribute
#		define ST_HAS_CPP_ATTRIBUTE(Attribute) __has_cpp_attribute(Attribute)
#	else
#		define ST_HAS_CPP_ATTRIBUTE(Attribute) 0
#	endif

#	if ST_HAS_CPP_ATTRIBUTE(nodiscard)
#		define NODISCARD [[nodiscard]]
#	else
#		define NODISCARD
#	endif

#	if ST_HAS_CPP_ATTRIBUTE(noreturn)
#		define NORETURN [[noreturn]]
#	else
#		define NORETURN
#	endif

#	if ST_HAS_CPP_ATTRIBUTE(maybe_unused)
#		define MAYBE_UNUSED [[maybe_unused]]
#	else
#		define MAYBE_UNUSED
#	endif

#	if ST_HAS_CPP_ATTRIBUTE(likely)
#		define LIKELY [[likely]]
#	else
#		define LIKELY
#	endif

#	if ST_HAS_CPP_ATTRIBUTE(unlikely)
#		define UNLIKELY [[unlikely]]
#	else
#		define UNLIKELY
#	endif

#	if ST_HAS_CPP_ATTRIBUTE(deprecated)
#		define DEPRECATED [[deprecated]]
#		define DEPRECATED_MSG(Message) [[deprecated(Message)]]
#	else
#		define DEPRECATED
#		define DEPRECATED_MSG(Message)
#	endif
#pragma endregion  // Attributes

#pragma region CompilerSpecifics
#	if ST_COMPILER_CLANG
#		define FORCEINLINE __attribute__((always_inline))
#		define NOINLINE __attribute__((noinline))
#		define DLL_EXPORT __attribute__((visibility("default")))
#		define DLL_IMPORT __attribute__((visibility("default")))
#	elif ST_COMPILER_GCC
#		define FORCEINLINE __attribute__((always_inline))
#		define NOINLINE __attribute__((noinline))
#		define DLL_EXPORT __attribute__((visibility("default")))
#		define DLL_IMPORT __attribute__((visibility("default")))
#	elif ST_COMPILER_MSVC
#		define FORCEINLINE __forceinline
#		define NOINLINE __declspec(noinline)
#		define DLL_EXPORT __declspec(dllexport)
#		define DLL_IMPORT __declspec(dllimport)
#	endif
#pragma endregion // CompilerSpecifics
