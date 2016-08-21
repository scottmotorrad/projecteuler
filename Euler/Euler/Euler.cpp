#include <iostream>

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

int main()
{
	std::cout << "Solution: " << problem3() << std::endl;
	return 0;
}

