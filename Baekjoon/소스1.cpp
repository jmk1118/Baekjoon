#include <iostream>
#include <string> //getline을 쓰기 위함

int main(void)
{
	std::string sentence;
	std::getline(std::cin, sentence);

	int voca = 0;
	for (int i = 1; i < sentence.size(); i++)
	{
		if (sentence[i - 1] != ' ' && sentence[i] == ' ')
			voca++;
	}

	if (sentence.back() == ' ')
		std::cout << voca;
	else
		std::cout << voca + 1;
}