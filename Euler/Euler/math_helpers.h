#pragma once

#include<cstdint>

bool isPalindromeNumber(int p);
bool isSpecialPythagoreanTriplet(int64_t a, int64_t b, int64_t c);

template<class T>
T max(T a, T b) {
	if (a < b)
		return b;
	return a;
}