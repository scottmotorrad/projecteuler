#include <iostream>

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

int main()
{
	std::cout << "Solution: " << problem2() << std::endl;
	return 0;
}

