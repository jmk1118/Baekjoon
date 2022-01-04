#include <iostream>
#include <string> //to_string 연산을 위해 필요

int main(void)
{
	int a, b, c;
	int answer;

	std::cin >> a >> b >> c;
	answer = a * b * c;

	std::string voca = std::to_string(answer);
	
	int numberCheck[10] = { 0, };
	for (int i = 0; i < voca.size(); i++)
	{
		numberCheck[voca[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << numberCheck[i] << "\n";
	}
}