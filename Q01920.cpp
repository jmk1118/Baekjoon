#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>

int main(void)
{
	int n;
	scanf("%d", &n);
	int Nnumber[100000];
	for (int i = 0; i < n; i++)
		scanf("%d", &Nnumber[i]);
	std::sort(Nnumber, Nnumber + n);

	int m;
	scanf("%d", &m);
	int Mnumber[100000];
	for (int i = 0; i < m; i++)
		scanf("%d", &Mnumber[i]);

	int check, startcheck, lastcheck;
	for (int i = 0; i < m; i++)
	{
		startcheck = 0;
		lastcheck = n - 1;
		check = (startcheck + lastcheck) / 2;
		while (Nnumber[check] != Mnumber[i] && startcheck < lastcheck)
		{
			if (Nnumber[check] < Mnumber[i])
			{
				startcheck = check + 1;
				check = (startcheck + lastcheck) / 2;
			}
			else
			{
				lastcheck = check - 1;
				check = (startcheck + lastcheck) / 2;
			}
		}
		if (Nnumber[check] == Mnumber[i])
			printf("1\n");
		else
			printf("0\n");
	}
}