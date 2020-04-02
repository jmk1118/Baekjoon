#include <iostream>
#include <algorithm>

int main(void)
{
	int n;
	int number[1000000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> number[i];
	}
	std::sort(number, number + n);

	for (int i = 0; i < n; i++)
		std::cout << number[i] << "\n";
}