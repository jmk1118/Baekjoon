#include <iostream>
#include <algorithm>

int main(void)
{
	int N; // 포도주 수
	std::cin >> N;

	int wine[10001][2]; // 0 : 이전 와인잔을 마시지 않았을 때 최대량, 1: 이전 와인잔을 마셨을 때 최대량
	// 0번째 잔 초기화
	wine[0][0] = 0;
	wine[0][1] = 0;
	// 1번째 잔 초기화
	std::cin >> wine[1][0];
	wine[1][1] = wine[1][0];
	// 2, 3번재 잔 초기화
	if (N >= 2)
	{
		std::cin >> wine[2][0];
		wine[2][1] = wine[1][0] + wine[2][0];
	}
	if (N >= 3)
	{
		std::cin >> wine[3][0];
		wine[3][1] = wine[2][0] + wine[3][0];
		wine[3][0] = wine[1][0] + wine[3][0];
	}
	// 1에는 이전 와인잔을 마셨을 경우의 최대량에 이번 와인잔을 더한다
	// 0일 경우에는 2칸 전, 3칸 전의 와인잔을 마셨을 경우의 최대량 중 가장 최대인 값에 이번 와인잔을 더한다
	// 4칸을 넘어갈 경우 그 사이에 와인잔을 마시는 편이 더 좋기 때문에 계산하지 않는다
	for (int i = 4; i <= N; i++)
	{
		std::cin >> wine[i][0];
		wine[i][1] = wine[i - 1][0] + wine[i][0];
		wine[i][0] = std::max(std::max(wine[i - 2][0], wine[i - 2][1]), std::max(wine[i - 3][0], wine[i - 3][1])) + wine[i][0];
	}

	// 마지막 잔을 마시거나 마시지 않는 경우가 있을 수 있기 떄문에 모두 비교해 정답을 출력한다
	std::cout << std::max(std::max(wine[N][0], wine[N][1]), wine[N - 1][1]);
}