#include <iostream>
#include "math_helpers.h"

typedef unsigned long long uint64;

// Sum of multiples of 3 and 5 < 1000
int problem1() {
	int count = 0;
	for (int i = 3; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			count += i;
	}
	return count;
}

//Sum of even Fibonacci  numbers
int problem2() {
	int fib = 1;
	int fibNm1 = 1;
	int temp = 1;
	int sum = 0;
	while (fib < 4000000) {
		temp = fib;
		fib += fibNm1;
		fibNm1 = temp;
		if (fib % 2 == 0) {
			sum += fib;
		}
	}
	return sum;
}

uint64 problem3() {
	uint64 compositeNumber = 600851475143ULL;
	uint64 largestFactor = 0ULL;
	for (uint64 i = 3ULL; i <= compositeNumber; i += 2ULL) {
		while (compositeNumber % i == 0) {
			compositeNumber /= i;
			largestFactor = i;
		}
	}
	return largestFactor;
}

int problem4() {
	int product = 0;
	int largestPalidromeNumber = 0;
	for (int factor1 = 999; factor1 > 99; factor1--) {
		for (int factor2 = factor1; factor2 > 99; factor2--) {
			product = factor1 * factor2;
			if (product > largestPalidromeNumber && isPalindromeNumber(product)) {
				largestPalidromeNumber = product;
				factor2 = 0; //exit the inner loop
			}
		}
	}
	return largestPalidromeNumber;
}

int main()
{
	std::cout << "Solution: " << problem4() << std::endl;
	return 0;
}

