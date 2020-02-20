#include <iostream>

int d(int now);

int main(void)
{
	int number[10001] = { 0, };

	int next;
	for (int i = 1; i < 10001; i++)
	{
		next = d(i);
		if (next < 10001)
			number[next]++;
	}

	for (int i = 1; i < 10001; i++)
	{
		if (number[i] == 0)
			std::cout << i << "\n";
	}
}

int d(int now)
{
	int next = now;
	next += now / 10000;
	next += (now / 1000) % 10;
	next += (now / 100) % 10;
	next += (now / 10) % 10;
	next += now % 10;

	return next;
}