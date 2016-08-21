#pragma once

bool isPalindromeNumber(int p);

template<class T>
T max(T a, T b) {
	if (a < b)
		return b;
	return a;
}