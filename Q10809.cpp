#include <iostream>

int main(void)
{
	int alpha[26];
	for (int i = 0; i < 26; i++)
		alpha[i] = -1;

	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (alpha[s[i] - 'a'] == -1)
			alpha[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		std::cout << alpha[i] << " ";
	}
}