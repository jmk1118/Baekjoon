#include <iostream>

int main(void)
{
	std::string voca;
	std::cin >> voca;
	int alpha[26] = { 0, };

	for (int i = 0; i < voca.size(); i++)
	{
		if (voca[i] >= 'a')
			alpha[voca[i] - 'a']++;
		else
			alpha[voca[i] - 'A']++;
	}

	bool twoMax = false;
	int max = 0;
	char maxAlpha = 'A';
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > max)
		{
			max = alpha[i];
			twoMax = false;
			maxAlpha = 'A' + i;
		}
		else if (alpha[i] == max)
			twoMax = true;
	}

	if (twoMax)
		std::cout << "?";
	else
		std::cout << maxAlpha;
}