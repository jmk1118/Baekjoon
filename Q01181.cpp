#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::string a, std::string b);

int main(void)
{
	int n;
	std::cin >> n;

	std::vector<std::string> voca;
	std::string now;
	for (int i = 0; i < n; i++)
	{
		std::cin >> now;
		voca.push_back(now);
	}
	std::sort(voca.begin(), voca.end(), compare);
	std::cout << voca.at(0) << "\n";
	for (int i = 1; i < n; i++)
	{
		if (voca.at(i) != voca.at(i - 1))
			std::cout << voca.at(i) << "\n";
	}
}

bool compare(std::string a, std::string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}