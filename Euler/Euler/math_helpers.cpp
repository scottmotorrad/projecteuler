#include "math_helpers.h"

bool isPalindromeNumber(int p) {
	int digits = 1;
	int counter = 10;
	while (p > counter) {
		counter *= 10;
		digits++;
	}
	char* str = new char[digits];
	counter = 0;
	while (p > 0) {
		str[counter] = (char)((p % 10) + 48);
		p /= 10;
		counter++;
	}

	for (int i = 0; i < digits / 2; i++) {
		if (str[i] != str[digits - (i + 1)])
			return false;
	}
	delete[] str;
	return true;
}