#include <iostream>

int main(void)
{
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;

	int answer = x;
	if (answer > y)
		answer = y;
	if (answer > w - x)
		answer = w - x;
	if (answer > h - y)
		answer = h - y;

	std::cout << answer;
}