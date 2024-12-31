#include "pch.h"

#include <cstdio>

#include "Substance/Core/Containers/Array.h"

struct FTest
{
	uint32 Value = 69;
};

int main()
{
	CONSTEXPR TArray<FTest, 10> TestArray = {{255}};
	for (const FTest& Value : TestArray)
		printf("%u\n", Value.Value);
	printf("First: %u\n", TestArray.GetFirstElement().Value);
	return 0;
}
