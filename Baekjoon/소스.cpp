#include <iostream>
#include <algorithm>

int N; // 팀의 수
int S[21][21]; // 입력받은 능력치
int min; // 1팀과 2팀의 능력치 차이 최솟값
bool ateam[21]; // 1팀에 들어간 선수는 true가 된다.

void AddPerson(int nextPerson, int size);
int CalculateStats();

int main(void)
{
	std::cin >> N; // N 입력
	
	// S 입력
	for (int i = 1; i <= N; i++)
	{
		for (int o = 1; o <= N; o++)
		{
			std::cin >> S[i][o];
		}
		ateam[i] = false; // 1팀 초기화
	}

	min = 2147483647; // 최솟값 초기화

	// AddPerson을 호출한다. nextPerson을 1에서 2/N + 1까지만 넣는다.
	for (int i = 1; i <= N / 2 + 1; i++)
	{
		AddPerson(i, 1);
	}

	// min을 출력한다.
	std::cout << min;
}

/// <summary>
/// 1팀에 2/N만큼의 선수를 백트래킹으로 채워주는 함수
/// </summary>
/// <param name="nextPerson">1팀에 넣을 다음 선수</param>
/// <param name="size">1팀에 들어간 선수들의 수</param>
void AddPerson(int nextPerson, int size)
{
	// nextPerson을 1팀에 넣는다.
	ateam[nextPerson] = true;

	// size가 2/N과 같다면 CalculateStats()를 호출하여 min과 비교해 더 작은 값은 min에 저장하고 nextPerson을 1팀에서 뺀후 함수를 종료한다.
	if (size == N / 2)
	{
		min = std::min(min, CalculateStats());
		ateam[nextPerson] = false;
		return;
	}

	// size가 2/N보다 작다면 AddPerson을 다시 한번 호출한다. nextPerson은 현재 값보다 큰 숫자부터 넣는다. size는 +1한다.
	// size가 2/N이 안됐는데 nextPerson이 N과 같다면 nextPerson을 1팀에서 빼고 함수를 종료한다.
	if (nextPerson >= N)
	{
		ateam[nextPerson] = false;
		return;
	}
	else if (size < N /2)
	{
		for (int i = nextPerson + 1; i <= N; i++)
		{
			AddPerson(i, size + 1);
		}
	}

	// nextPerson을 1팀에서 빼고 함수를 종료한다.
	ateam[nextPerson] = false;
	return;
}

int CalculateStats()
{
	int ateamStats = 0; // 1팀 능력치
	int bteamStats = 0; // 2팀 능력치

	// 1팀 능력치 계산
	// 2팀 능력치 계산
	for (int i = 1; i < N; i++)
	{
		if (ateam[i]) // 1팀 능력치 계산
		{
			for (int o = i + 1; o <= N; o++)
			{
				if (ateam[o])
				{
					ateamStats += S[i][o];
					ateamStats += S[o][i];
				}
			}
		}
		else // 2팀 능력치 계산
		{
			for (int o = i + 1; o <= N; o++)
			{
				if (!ateam[o])
				{
					bteamStats += S[i][o];
					bteamStats += S[o][i];
				}
			}
		}
	}

	// 1팀 능력치 - 2팀 능력치
	// 양수면 반환, 음수면 -1 곱해서 반환
	if (ateamStats - bteamStats >= 0)
	{
		return ateamStats - bteamStats;
	}
	else
	{
		return bteamStats - ateamStats;
	}
}