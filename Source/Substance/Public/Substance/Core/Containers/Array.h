#pragma once

#include "Substance/Core/CoreAPI.h"
#include "Substance/Core/CoreCompiler.h"
#include "Substance/Core/Types/PrimitiveTypes.h"

#include "Substance/Core/Containers/Iterator.h"

template <typename TElement, size64 TSize> requires std::is_default_constructible_v<TElement>
class LIBRARY_API TArray
{
public:
	CONSTEXPR TArray() = default;
	CONSTEXPR TArray(std::initializer_list<TElement> InitializerList)
	{
		for (size64 Index = 0; Index < TSize; ++Index)
		{
			if (Index < InitializerList.size())
				Elements[Index] = InitializerList.begin()[Index];
			else
				Elements[Index] = TElement();
		}
	}

	CONSTEXPR TArray(const TArray& Other) = default;
	CONSTEXPR TArray(TArray&& Other) = default;
	CONSTEXPR TArray& operator=(const TArray& Other) = default;
	CONSTEXPR TArray& operator=(TArray&& Other) = default;

	CONSTEXPR ~TArray() = default;

public:
	NODISCARD CONSTEXPR TElement& At(size64 Index) { return Elements[Index]; }
	NODISCARD CONSTEXPR const TElement& At(const size64 Index) const { return At(Index); }

	NODISCARD CONSTEXPR TElement& GetFirstElement() { return Elements[0]; }
	NODISCARD CONSTEXPR const TElement& GetFirstElement() const { return Elements[0]; }

	NODISCARD CONSTEXPR TElement& GetLastElement() { return Elements[TSize - 1]; }
	NODISCARD CONSTEXPR const TElement& GetLastElement() const { return Elements[TSize - 1]; }

	NODISCARD CONSTEXPR TIterator<TElement, TSize> GetFrontIterator() { return TIterator<TElement, TSize>(Elements); }
	NODISCARD CONSTEXPR TConstIterator<TElement, TSize> GetFrontIterator() const { return TConstIterator<TElement, TSize>(Elements); }

	NODISCARD CONSTEXPR TIterator<TElement, TSize> GetBackIterator() { return TIterator<TElement, TSize>(Elements + TSize); }
	NODISCARD CONSTEXPR TConstIterator<TElement, TSize> GetBackIterator() const { return TConstIterator<TElement, TSize>(Elements + TSize); }

public:
	// Only for compatibility with range-based for loops
	NODISCARD CONSTEXPR TIterator<TElement, TSize> begin() { return GetFrontIterator(); }
	NODISCARD CONSTEXPR TConstIterator<TElement, TSize> begin() const { return GetFrontIterator(); }
	NODISCARD CONSTEXPR TConstIterator<TElement, TSize> cbegin() const { return GetFrontIterator(); }

	NODISCARD CONSTEXPR TIterator<TElement, TSize> end() { return GetBackIterator(); }
	NODISCARD CONSTEXPR TConstIterator<TElement, TSize> end() const { return GetBackIterator(); }
	NODISCARD CONSTEXPR TConstIterator<TElement, TSize> cend() const { return GetBackIterator(); }

public:
	NODISCARD CONSTEXPR TElement& operator[](size64 Index) { return Elements[Index]; }
	NODISCARD CONSTEXPR const TElement& operator[](const size64 Index) const { return operator[](Index); }

public:
	NODISCARD CONSTEXPR TElement* GetData() { return Elements; }
	NODISCARD CONSTEXPR const TElement* GetData() const { return GetData(); }

public:
	static NODISCARD CONSTEXPR size64 GetSize() { return TSize; }

private:
	TElement Elements[TSize];
};
