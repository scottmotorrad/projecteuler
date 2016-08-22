#include <iostream>
#include "math_helpers.h"
#include <cstdint>

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
int64_t problem3() {
	int64_t compositeNumber = 600851475143LL;
	int64_t largestFactor = 0LL;
	for (int64_t i = 3LL; i <= compositeNumber; i += 2LL) {
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
int64_t problem6() {
	int64_t sumOfSquares = 0;
	int64_t squareofSum = 0;
	for (int64_t i = 1LL; i <= 100LL; i++) {
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

// Largest product of consecutive integers
int64_t problem8() {
	char c[1001] = 
		"73167176531330624919225119674426574742355349194934"
		"96983520312774506326239578318016984801869478851843"
		"85861560789112949495459501737958331952853208805511"
		"12540698747158523863050715693290963295227443043557"
		"66896648950445244523161731856403098711121722383113"
		"62229893423380308135336276614282806444486645238749"
		"30358907296290491560440772390713810515859307960866"
		"70172427121883998797908792274921901699720888093776"
		"65727333001053367881220235421809751254540594752243"
		"52584907711670556013604839586446706324415722155397"
		"53697817977846174064955149290862569321978468622482"
		"83972241375657056057490261407972968652414535100474"
		"82166370484403199890008895243450658541227588666881"
		"16427171479924442928230863465674813919123162824586"
		"17866458359124566529476545682848912883142607690042"
		"24219022671055626321111109370544217506941658960408"
		"07198403850962455444362981230987879927244284909188"
		"84580156166097919133875499200524063689912560717606"
		"05886116467109405077541002256983155200055935729725"
		"71636269561882670428252483600823257530420752963450";
	int n[1000];
	for (int i = 0; i < 1000; i++) {
		n[i] = (int)c[i] - 48;
	}
	int64_t maxProduct = 0;
	for (int i = 0; i < 1000 - 12; i++) {
		int64_t product = (int64_t)n[i];
		for (int j = 1; j < 13; j++) {
			product *= (int64_t)n[j + i];
		}
		maxProduct = max<int64_t>(maxProduct, product);
	}
	return maxProduct;
}

// Special Pythagorean triplet where a + b + c == 1000
int64_t problem9() {
	for (int64_t a = 1; a < 332; a++) // 332 + 333 + 334 == 999
		for (int64_t b = a + 1; b < 500; b++) // 1 + 499 + 5000 == 1000
			for (int64_t c = b + 1; c < 997; c++) // 1 + 2 + 997 = 1000
				if (a + b + c == 1000 && isSpecialPythagoreanTriplet(a, b, c))
					return a * b * c;
	return -1;
}

int main()
{
	std::cout << "Solution: " << problem9() << std::endl;
	return 0;
}

