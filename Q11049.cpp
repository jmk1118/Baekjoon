#include <iostream>
#include <algorithm>

int main(void)
{
	int n;
	std::cin >> n;

	int r[501];
	int c[501];
	for (int i = 1; i <= n; i++)
		std::cin >> r[i] >> c[i];

	long long int dp[501][501] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		for (int o = 1; o + i <= n; o++)
		{
			for (int p = o; p < o + i; p++)
			{
				if (dp[o][o + i] == 0)
					dp[o][o + i] = dp[o][p] + dp[p + 1][o + i] + r[o] * c[p] * c[o + i];
				else
					dp[o][o + i] = std::min(dp[o][o + i], dp[o][p] + dp[p + 1][o + i] + r[o] * c[p] * c[o + i]);
			}
		}
	}

	std::cout << dp[1][n];

	return 0;
}