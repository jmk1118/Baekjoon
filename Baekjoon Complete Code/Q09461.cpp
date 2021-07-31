#include <iostream>

int main(void)
{
	int T, N; // 입력값

	long long int PN[101]; // 수열, P(100)의 값이 int의 범위를 넘어가기 떄문에 long long int를 사용한다.
	// P(N) 수열 1~5 초기화
	PN[1] = 1;
	PN[2] = 1;
	PN[3] = 1;
	PN[4] = 2;
	PN[5] = 2;
	// P(N) = P(N-5) + P(N-1)인 점화식으로 수열을 채운다.
	for (int i = 6; i <= 100; i++)
	{
		PN[i] = PN[i - 5] + PN[i - 1];
	}

	std::cin >> T;

	for (int i = 1; i <= T; i++)
	{
		std::cin >> N;

		printf("%lld\n", PN[N]);
	}
}