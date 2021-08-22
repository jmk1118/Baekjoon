#include <iostream>
#include <algorithm>

int main(void)
{
	int N; // 입력값
	std::cin >> N;

	int sum[501]; // 이전줄 기록용
	int now[501]; // 현재줄 기록용

	std::cin >> sum[1]; // 첫 값 입력
	for (int i = 2; i <= N; i++) // 1칸씩 늘려가며 입력
	{
		// 첫 숫자는 오른쪽 위 숫자에서만 값을 받으므로, 오른쪽 위 값을 더해서 저장
		std::cin >> now[1];
		now[1] = sum[1] + now[1];

		for (int o = 2; o <= i - 1; o++)
		{
			// 2번째 ~ 마지막 전 숫자는 왼쪽 혹은 오른쪽 숫자 중 큰 값을 받아야 하므로 max로 선택
			std::cin >> now[o];
			now[o] = std::max(sum[o - 1] + now[o], sum[o] + now[o]);

			// 이전줄의 2칸 이하는 더이상 쓰지 않으므로 업데이트한다
			sum[o - 1] = now[o - 1];
		}
		
		// 마지막 숫자는 왼쪽 위 숫자에서만 값을 받으므로, 왼쪽 위 값을 더해서 저장
		std::cin >> now[i];
		sum[i] = sum[i - 1] + now[i];

		// 업데이트하지 못한 i-1번째 숫자 업데이트
		sum[i - 1] = now[i - 1];
	}

	// 답 출력
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		answer = std::max(answer, sum[i]);
	}

	std::cout << answer;
}