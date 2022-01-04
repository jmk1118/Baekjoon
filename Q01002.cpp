#include <iostream>
#include <cmath>

int main(void)
{
	int t;
	std::cin >> t;

	int x1, y1, r1, x2, y2, r2;
	double dist;
	for (int i = 0; i < t; i++)
	{
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
				std::cout << -1 << "\n";
			else
				std::cout << 0 << "\n";
			continue;
		}

		dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (r1 + r2 < dist || dist + r1 < r2 || dist + r2 < r1)
			std::cout << 0 << "\n";
		else if (r1 + r2 == dist || dist + r1 == r2 || dist + r2 == r1)
			std::cout << 1 << "\n";
		else
			std::cout << 2 << "\n";
	}
}