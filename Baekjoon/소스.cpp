#include <iostream>

int n, m; // 수열의 최댓값과 수열의 길이
int answer[9]; // 조건에 맞는 수열을 저장하는 배열

void backTracking(int nowlength, int value); // 백트래킹을 하는 DFS 함수

int main(void)
{
	std::cin >> n >> m; // n, m 입력

	// 첫 번째 값을 입력하고 백트래킹 함수를 실행한다. 
	// 첫 번째 값은 1부터 n까지 존재한다.
	for (int i = 1; i <= n; i++)
	{
		answer[1] = i;
		if (m == 1) // 만약 수열의 길이가 1이라면 백트래킹을 돌리지 않고 그대로 출력한다.
		{
			printf("%d\n", answer[1]);
			continue;
		}

		for (int o = 1; o <= n; o++) // 같은 수를 여러번 골라도 괜찮으므로 1부터 n까지 모든 숫자를 백트래킹한다.
			backTracking(2, o);
	}
}

/// <summary>
/// 백트래킹 함수
/// </summary>
/// <param name="nowlength">현재 함수에서 입력할 수열의 위치</param>
/// <param name="value">현재 함수에서 수열에 입력할 값</param>
void backTracking(int nowlength, int value)
{
	answer[nowlength] = value; // 입력받은 위치에 입력받은 값을 집어넣는다.

	if (nowlength >= m) // 입력받은 값들에 의해 수열의 길이가 m이 되었다면 수열을 출력하고 부모 노드로 돌아간다.
	{
		for (int i = 1; i <= m; i++)
			printf("%d ", answer[i]);
		printf("\n");

		return;
	}

	for (int i = 1; i <= n; i++) // 같은 수를 여러번 골라도 괜찮으므로 1부터 n까지 모든 숫자를 백트래킹한다.
	{
		backTracking(nowlength + 1, i);
	}
}