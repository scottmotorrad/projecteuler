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

// Sum of even Fibonacci  numbers
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

// Largest prime factor
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

// Largest palindrome number
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

// Smallest multiple of 1,2,3...20
int problem5() {
	bool multiple = false;
	for (int i = 20; !multiple; i += 2) {
		multiple = true;
		for (int j = 1; j < 21 && multiple; j++)
			multiple = multiple && i % j == 0;
		if (multiple)
			return i;
	}
}

// Sum square difference
uint64 problem6() {
	uint64 sumOfSquares = 0;
	uint64 squareofSum = 0;
	for (uint64 i = 1ULL; i <= 100ULL; i++) {
		squareofSum += i;
		sumOfSquares += i * i;
	}
	squareofSum *= squareofSum;
	return squareofSum - sumOfSquares;
}

// 10001st prime
int problem7() {
	int* primes = new int[10001];
	primes[0] = 2;
	primes[1] = 3;
	int primeCounter = 2;
	for (int i = 5; primeCounter < 10001; i += 2) {
		bool isPrime = true;
		for (int j = 1; j <= primeCounter && isPrime; j++) {
			isPrime = isPrime && i % primes[j] != 0;
		}
		if (isPrime) {
			primes[primeCounter] = i;
			primeCounter++;
		}
	}
	int result = primes[10000];
	delete[] primes;
	return result;
}

int main()
{
	std::cout << "Solution: " << problem7() << std::endl;
	return 0;
}

