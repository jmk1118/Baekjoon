#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, std::string> a, std::pair<int, std::string> b);

int main(void)
{
	int n;
	std::cin >> n;

	std::vector<std::pair<int, std::string>> person;
	int year;
	std::string name;
	for (int i = 0; i < n; i++)
	{
		std::cin >> year >> name;
		person.push_back(std::pair<int, std::string>(year, name));
	}
	std::stable_sort(person.begin(), person.end(), compare);
	for (int i = 0; i < n; i++)
		std::cout << person.at(i).first << " " << person.at(i).second << "\n";
}

bool compare(std::pair<int, std::string> a, std::pair<int, std::string> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return false;
}