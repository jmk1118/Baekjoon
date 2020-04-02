#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> point;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x >> y;
		point.push_back(std::pair<int, int>(x, y));
	}
	std::sort(point.begin(), point.end());

	for (int i = 0; i < point.size(); i++)
		std::cout << point.at(i).first << " " << point.at(i).second << "\n";
}