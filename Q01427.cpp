#include <iostream>
#include <algorithm>
#include <string>

int main(void)
{
	int n;
	std::cin >> n;

	int number[10];
	std::string voca = std::to_string(n);
	for (int i = 0; i < voca.size(); i++)
	{
		number[i] = voca.at(i) - 48;
	}
	std::sort(number, number + voca.size());
	for (int i = voca.size() - 1; i >= 0; i--)
		std::cout << number[i];
}