#include <iostream>
#include <string>
#include <vector>

int main(void)
{
	int n;
	std::cin >> n;

	std::vector<int> devil;
	int now = 665;
	std::string nowCheck;
	while(devil.size() < n)
	{
		now++;
		nowCheck = std::to_string(now);
		if (nowCheck.find("666") != std::string::npos)
			devil.push_back(now);
	}

	std::cout << devil.back();
}