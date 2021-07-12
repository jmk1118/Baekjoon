#include <iostream>
#include <string>
#include <stack>

int main(void)
{
	std::string a;
	std::string b;
	std::cin >> a >> b;

	int length;
	if (a.length() > b.length())
		length = a.length() + 1;
	else
		length = b.length() + 1;

	std::stack<int> answer;
	int anum, bnum, nextnum = 0;
	int alength = a.length();
	int blength = b.length();
	for (int i = 0; i < length; i++)
	{
		if (alength >= i + 1)
			anum = a.at(alength - i - 1) - '0';
		else
			anum = 0;

		if (blength >= i + 1)
			bnum = b.at(blength - i - 1) - '0';
		else
			bnum = 0;

		if (anum + bnum + nextnum >= 10)
		{
			answer.push((anum + bnum + nextnum) % 10);
			nextnum = (anum + bnum + nextnum) / 10;
		}
		else
		{
			answer.push(anum + bnum + nextnum);
			nextnum = 0;
		}
	}

	if (answer.top() == 0)
		answer.pop();
	int answersize = answer.size();
	for (int i = 0; i < answersize; i++)
	{
		std::cout << answer.top();
		answer.pop();
	}
}