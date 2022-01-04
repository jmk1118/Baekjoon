#include <iostream>

int Nnumber[1000001] = { 0, };

int main(void)
{
	int N; // 입력값
	std::cin >> N;

	// N이 1이나 2라면 바로 값을 출력하고, 아니라면 동적계획법으로 점화식을 계산해서 출력
	if (N == 1)
		printf("1");
	else if (N == 2)
		printf("2");
	else
	{
		// 점화식 초기값 입력
		Nnumber[1] = 1;
		Nnumber[2] = 2;
		
		// 점화식 계산
		for (int i = 3; i <= N; i++)
		{
			// 수가 커짐을 방지하기 위해 15746으로 나눈 값을 집어넣는다.
			// 점화식이 덧셈이므로 15746의 나머지끼리만 더해도 옳은 값을 구할 수 있다.
			Nnumber[i] = (Nnumber[i - 2] + Nnumber[i - 1]) % 15746;
		}
		printf("%d", Nnumber[N]);
	}
}