#include <iostream>

int main(void)
{
	bool number[10001] = { 0, };
	number[1] = true;

	int count;
	for (int i = 2; i <= 10000; i++)
	{
		if (number[i] == false)
		{
			count = 2;
			while (i * count <= 10000)
			{
				number[i * count] = true;
				count++;
			}
		}
	}

	int t, n;
	int down, up;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		down = n / 2;
		up = n / 2;

		while (number[down] != false || number[up] != false)
		{
			down--;
			up++;
		}
		std::cout << down << " " << up << "\n";
	}
}