#include <iostream>

int main(void)
{
	int num, num2;
	int first, end;
	int count = 1;

	std::cin >> num;

	first = num / 10;
	end = num % 10;

	num2 = end * 10 + (first + end) % 10;

	while (num != num2)
	{
		first = num2 / 10;
		end = num2 % 10;

		num2 = end * 10 + (first + end) % 10;
		count++;
	}

	std::cout << count << "\n";
}