#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> hanoi;
void moveTop(int n, int start, int fin, int mid);

int main(void)
{
	int n;
	std::cin >> n;

	moveTop(n, 1, 3, 2);

	std::cout << hanoi.size() << "\n";
	for (int i = 0; i < hanoi.size(); i++)
	{
		std::cout << hanoi.at(i).first << " " << hanoi.at(i).second << "\n";
	}
}

void moveTop(int n, int start, int fin, int mid)
{
	if (n == 1)
	{
		hanoi.push_back(std::pair<int, int>(start, fin));
		return;
	}

	moveTop(n - 1, start, mid, fin);
	hanoi.push_back(std::pair<int, int>(start, fin));
	moveTop(n - 1, mid, fin, start);
}