#include <iostream>

int main(void)
{
	int t;
	int r;
	std::string s;

	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		std::cin >> r >> s;
		for (int o = 0; o < s.size(); o++)
		{
			for (int p = 0; p < r; p++)
			{
				std::cout << s[o];
			}
		}
		std::cout << "\n";
	}
}