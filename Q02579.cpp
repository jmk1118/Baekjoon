#include <iostream>
#include <algorithm>

int main(void)
{
	int stairNum; // 계단 수
	std::cin >> stairNum;

	int stairMaxPoint[301][2]; // [x][0] : 직전에 2칸을 띄워 올라온 합계 값, [x][1] : 직전에 1칸을 띄워 올라온 합계 값
	std::cin >> stairMaxPoint[1][0]; // 1번 계단
	stairMaxPoint[1][1] = 0; // 만약 stairNum이 1일 경우 마지막에 max로 계산할 수 있도록 값을 할당한다
	if (stairNum >= 2)
	{
		std::cin >> stairMaxPoint[2][0]; // 2번 계단
		stairMaxPoint[2][1] = stairMaxPoint[1][0] + stairMaxPoint[2][0]; // 1번 계단 + 2번 계단
	}
	if (stairNum >= 3)
	{
		std::cin >> stairMaxPoint[3][0]; // 3번 계단
		stairMaxPoint[3][1] = stairMaxPoint[2][0] + stairMaxPoint[3][0]; // 2번 계단 + 3번 계단
		stairMaxPoint[3][0] = stairMaxPoint[1][0] + stairMaxPoint[3][0]; // 1번 계단 + 3번 계단
	}

	for (int i = 4; i <= stairNum; i++)
	{
		std::cin >> stairMaxPoint[i][0]; // i번 계단의 값

		// 3칸 연속을 쓰지 못하므로 이전 계단은 2칸 띄워서 온 값을 더한다
		stairMaxPoint[i][1] = stairMaxPoint[i - 1][0] + stairMaxPoint[i][0];

		// 2칸 전의 계단은 1칸 띄워서 온 값이든 2칸 띄워서 온 값이든 상관 없으므로 둘 중 큰 값을 더한다
		stairMaxPoint[i][0] = std::max(stairMaxPoint[i - 2][0], stairMaxPoint[i - 2][1]) + stairMaxPoint[i][0];
	}

	std::cout << std::max(stairMaxPoint[stairNum][0], stairMaxPoint[stairNum][1]);
}