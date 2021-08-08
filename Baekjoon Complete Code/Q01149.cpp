#include <iostream>
#include <algorithm>

int answerRGB[1001][3]; // 마지막에 R을 칠했을 때, G를 칠했을 때, B를 칠했을 때 각각의 최솟값

int main(void)
{
	int N, R, G, B;
	std::cin >> N;

	// 첫번째 값 입력
	std::cin >> answerRGB[1][0] >> answerRGB[1][1] >> answerRGB[1][2];

	// 2번째 이후 값 입력
	for (int i = 2; i <= N; i++)
	{
		std::cin >> R >> G >> B; // RGB값 입력
		
		// 이전 색상과 겹치지 않게 조합하여 최솟값을 저장한다
		answerRGB[i][0] = std::min(answerRGB[i - 1][1] + R, answerRGB[i - 1][2] + R);
		answerRGB[i][1] = std::min(answerRGB[i - 1][0] + G, answerRGB[i - 1][2] + G);
		answerRGB[i][2] = std::min(answerRGB[i - 1][0] + B, answerRGB[i - 1][1] + B);
	}

	// 마지막이 R, G, B인 조합 중 최솟값을 출력한다.
	int answer = std::min(answerRGB[N][0], answerRGB[N][1]);
	answer = std::min(answer, answerRGB[N][2]);
	printf("%d\n", answer);
}