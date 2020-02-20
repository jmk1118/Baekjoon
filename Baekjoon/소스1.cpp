#include <iostream>

bool han(int num);

int main(void)
{
	int n;
	std::cin >> n;

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (han(i))
			count++;
	}

	std::cout << count;
}

bool han(int num)
{
	int first = num / 1000;
	int second = (num / 100) % 10;
	int third = (num / 10) % 10;
	int final = num % 10;

	if (first == 0)
		if (second == 0) //1~2자리 숫자의 경우
			return true;
		else
			if (second - third == third - final)
				return true;
			else
				return false;
	else
		return false;
}