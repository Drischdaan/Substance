#pragma once

#include <cstdint>

#include "Substance/Core/CoreCompiler.h"

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

STATIC_ASSERT(sizeof(int8) == 1, "int8 size is not 1 byte");
STATIC_ASSERT(sizeof(int16) == 2, "int16 size is not 2 bytes");
STATIC_ASSERT(sizeof(int32) == 4, "int32 size is not 4 bytes");
STATIC_ASSERT(sizeof(int64) == 8, "int64 size is not 8 bytes");

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

STATIC_ASSERT(sizeof(uint8) == 1, "uint8 size is not 1 byte");
STATIC_ASSERT(sizeof(uint16) == 2, "uint16 size is not 2 bytes");
STATIC_ASSERT(sizeof(uint32) == 4, "uint32 size is not 4 bytes");
STATIC_ASSERT(sizeof(uint64) == 8, "uint64 size is not 8 bytes");

using float32 = float;
using float64 = double;

STATIC_ASSERT(sizeof(float32) == 4, "float32 size is not 4 bytes");
STATIC_ASSERT(sizeof(float64) == 8, "float64 size is not 8 bytes");

using size64 = size_t;

STATIC_ASSERT(sizeof(size64) == 8, "size64 size is not 8 bytes");

using bool8 = bool;

STATIC_ASSERT(sizeof(bool8) == 1, "bool8 size is not 1 byte");

using byte = uint8;

STATIC_ASSERT(sizeof(byte) == 1, "byte size is not 1 byte");
