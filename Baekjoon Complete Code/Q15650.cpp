#include <iostream>

int n, m; // 수열의 최댓값과 수열의 길이
int answer[9]; // 조건에 맞는 수열을 저장하는 배열

void backTracking(int nowlength, int value); // 백트래킹을 하는 DFS 함수

int main(void) 
{
	std::cin >> n >> m; // n, m 입력

	// 첫 번째 값을 입력하고 백트래킹 함수를 실행한다. 
	// 첫 번째 값은 1부터 n - m + 1까지만 입력될 수 있다. m만큼의 길이가 출력되야 하기 떄문이다.
	for (int i = 1; i <= n - m + 1; i++)
	{
		answer[1] = i;
		if (m == 1) // 만약 수열의 길이가 1이라면 백트래킹을 돌리지 않고 그대로 출력한다.
		{
			std::cout << answer[1] << std::endl;
			continue;
		}

		for (int o = i + 1; o <= n; o++) // 수열은 오름차순이므로 첫 번째 값에 입력한 수보다 큰 수를 차례대로 백트래킹 함수에 입력한다.
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
			std::cout << answer[i] << " ";
		std::cout << std::endl;

		return;
	}

	for (int i = value + 1; i <= n; i++) // 수열은 오름차순이므로 첫 번째 값에 입력한 수보다 큰 수를 차례대로 백트래킹 함수에 입력한다.
	{
		backTracking(nowlength + 1, i);
	}
}