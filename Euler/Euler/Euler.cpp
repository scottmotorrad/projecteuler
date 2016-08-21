#include <iostream>

//Multiples of 3 and 5
int problem1() {
	int count = 0;
	for (int i = 3; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			count += i;
	}
	return count;
}




int main()
{
	std::cout << "Solution: " << problem1() << std::endl;
	return 0;
}

