#include <iostream>

int wValue[51][51][51]; // w의 값을 저장하는 배열

int main(void)
{
	int a, b, c; // 입력값

	// wValue 0~20 사이의 값을 채운다.
	for (int i = 0; i <= 20; i++)
	{
		for (int o = 0; o <= 20; o++)
		{
			for (int p = 0; p <= 20; p++)
			{
				// i, o, p 중 하나가 0이라면 값을 1로 채운다.
				if (i == 0 || o == 0 || p == 0)
				{
					wValue[i][o][p] = 1;
					continue;
				}

				// 문제의 조건에 맞게 wValue의 이전 값들을 사용해 w(i, o. p)의 값을 구한다.
				if (i < o && o < p)
				{
					wValue[i][o][p] = wValue[i][o][p - 1] + wValue[i][o - 1][p - 1] - wValue[i][o - 1][p];
				}
				else
				{
					wValue[i][o][p] = wValue[i - 1][o][p] + wValue[i - 1][o - 1][p] + wValue[i - 1][o][p - 1] - wValue[i - 1][o - 1][p - 1];
				}
			}
		}
	}


	// 입력값을 받고 해당 입력값에 맞는 값은 wValue에서 찾아 출력한다.
	std::cin >> a >> b >> c;
	while (a != -1 || b != -1 || c != -1)
	{
		if (a <= 0 || b <= 0 || c <= 0)
		{
			printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
		}
		else if (a > 20 || b > 20 || c > 20)
		{
			printf("w(%d, %d, %d) = %d\n", a, b, c, wValue[20][20][20]);
		}
		else
		{
			printf("w(%d, %d, %d) = %d\n", a, b, c, wValue[a][b][c]);
		}

		std::cin >> a >> b >> c; // 다음값 입력받기
	}
}