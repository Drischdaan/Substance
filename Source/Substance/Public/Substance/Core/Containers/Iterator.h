#pragma once

#include "Substance/Core/CoreAPI.h"
#include "Substance/Core/CoreCompiler.h"
#include "Substance/Core/Types/PrimitiveTypes.h"

#include <array>

template <typename TElement, size64 TSize>
class LIBRARY_API TIterator
{
public:
	CONSTEXPR TIterator() = default;

	CONSTEXPR explicit TIterator(TElement* FirstElement, const size64 Offset = 0)
		: FirstElement(FirstElement), Offset(Offset)
	{
	}

public:
	// Access operators
	NODISCARD CONSTEXPR TElement* operator->() const { return FirstElement + Offset; }
	NODISCARD CONSTEXPR TElement& operator*() const { return *operator->(); }
	NODISCARD CONSTEXPR TElement& operator[](const size64 InOffset) const { return *(*this + InOffset); }

public:
	// Modification operators
	CONSTEXPR TIterator& operator++()
	{
		++Offset;
		return *this;
	}

	CONSTEXPR TIterator operator++(int)
	{
		TIterator Temp = *this;
		++Offset;
		return Temp;
	}

	CONSTEXPR TIterator& operator--()
	{
		--Offset;
		return *this;
	}

	CONSTEXPR TIterator operator--(int)
	{
		TIterator Temp = *this;
		--Offset;
		return Temp;
	}

	CONSTEXPR TIterator& operator+=(const size64 Value)
	{
		Offset += Value;
		return *this;
	}

	CONSTEXPR TIterator& operator-=(const size64 Value)
	{
		Offset -= Value;
		return *this;
	}

	CONSTEXPR TIterator operator+(const size64 InOffset) const
	{
		TIterator Temp = *this;
		Temp += InOffset;
		return Temp;
	}

	CONSTEXPR TIterator operator-(const size64 InOffset) const
	{
		TIterator Temp = *this;
		Temp -= InOffset;
		return Temp;
	}

public:
	// Comparison operators
	NODISCARD CONSTEXPR bool8 operator==(const TIterator& Other) const { return FirstElement + Offset == Other.FirstElement + Other.Offset; }

#if ST_CPP_VERSION >= ST_CPP_VERSION20
	NODISCARD CONSTEXPR bool8 operator<=>(const TIterator& Other) const { return Offset <=> Other.Offset; }
#else
	NODISCARD CONSTEXPR bool8 operator!=(const TIterator& Other) const { return !(*this == Other); }
	NODISCARD CONSTEXPR bool8 operator<(const TIterator& Other) const { return Offset < Other.Offset; }
	NODISCARD CONSTEXPR bool8 operator>(const TIterator& Other) const { return Offset > Other.Offset; }
	NODISCARD CONSTEXPR bool8 operator<=(const TIterator& Other) const { return Offset <= Other.Offset; }
	NODISCARD CONSTEXPR bool8 operator>=(const TIterator& Other) const { return Offset >= Other.Offset; }
#endif

private:
	TElement* FirstElement = nullptr;
	size64 Offset = 0;
};

template <typename TElement, size64 TSize>
class LIBRARY_API TConstIterator
{
public:
	CONSTEXPR TConstIterator() = default;

	CONSTEXPR explicit TConstIterator(const TElement* FirstElement, const size64 Offset = 0)
		: FirstElement(FirstElement), Offset(Offset)
	{
	}

public:
	// Access operators
	NODISCARD CONSTEXPR const TElement* operator->() const { return FirstElement + Offset; }
	NODISCARD CONSTEXPR const TElement& operator*() const { return *operator->(); }
	NODISCARD CONSTEXPR const TElement& operator[](const size64 InOffset) const { return *(*this + InOffset); }

public:
	// Modification operators
	CONSTEXPR TConstIterator& operator++()
	{
		++Offset;
		return *this;
	}

	CONSTEXPR TConstIterator operator++(int)
	{
		TIterator Temp = *this;
		++Offset;
		return Temp;
	}

	CONSTEXPR TConstIterator& operator--()
	{
		--Offset;
		return *this;
	}

	CONSTEXPR TConstIterator operator--(int)
	{
		TIterator Temp = *this;
		--Offset;
		return Temp;
	}

	CONSTEXPR TConstIterator& operator+=(const size64 Value)
	{
		Offset += Value;
		return *this;
	}

	CONSTEXPR TConstIterator& operator-=(const size64 Value)
	{
		Offset -= Value;
		return *this;
	}

	CONSTEXPR TConstIterator operator+(const size64 InOffset) const
	{
		TIterator Temp = *this;
		Temp += InOffset;
		return Temp;
	}

	CONSTEXPR TConstIterator operator-(const size64 InOffset) const
	{
		TIterator Temp = *this;
		Temp -= InOffset;
		return Temp;
	}

public:
	// Comparison operators
	NODISCARD CONSTEXPR bool8 operator==(const TConstIterator& Other) const { return FirstElement + Offset == Other.FirstElement + Other.Offset; }

#if ST_CPP_VERSION >= ST_CPP_VERSION20
	NODISCARD CONSTEXPR bool8 operator<=>(const TConstIterator& Other) const { return Offset <=> Other.Offset; }
#else
	NODISCARD CONSTEXPR bool8 operator!=(const TConstIterator& Other) const { return !(*this == Other); }
	NODISCARD CONSTEXPR bool8 operator<(const TConstIterator& Other) const { return Offset < Other.Offset; }
	NODISCARD CONSTEXPR bool8 operator>(const TConstIterator& Other) const { return Offset > Other.Offset; }
	NODISCARD CONSTEXPR bool8 operator<=(const TConstIterator& Other) const { return Offset <= Other.Offset; }
	NODISCARD CONSTEXPR bool8 operator>=(const TConstIterator& Other) const { return Offset >= Other.Offset; }
#endif

private:
	const TElement* FirstElement = nullptr;
	size64 Offset = 0;
};
