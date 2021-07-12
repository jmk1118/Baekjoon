#include <iostream>
#include <algorithm>

int N; // ���� ��
int S[21][21]; // �Է¹��� �ɷ�ġ
int min; // 1���� 2���� �ɷ�ġ ���� �ּڰ�
bool ateam[21]; // 1���� �� ������ true�� �ȴ�.

void AddPerson(int nextPerson, int size);
int CalculateStats();

int main(void)
{
	std::cin >> N; // N �Է�
	
	// S �Է�
	for (int i = 1; i <= N; i++)
	{
		for (int o = 1; o <= N; o++)
		{
			std::cin >> S[i][o];
		}
		ateam[i] = false; // 1�� �ʱ�ȭ
	}

	min = 2147483647; // �ּڰ� �ʱ�ȭ

	// AddPerson�� ȣ���Ѵ�. nextPerson�� 1���� 2/N + 1������ �ִ´�.
	for (int i = 1; i <= N / 2 + 1; i++)
	{
		AddPerson(i, 1);
	}

	// min�� ����Ѵ�.
	std::cout << min;
}

/// <summary>
/// 1���� 2/N��ŭ�� ������ ��Ʈ��ŷ���� ä���ִ� �Լ�
/// </summary>
/// <param name="nextPerson">1���� ���� ���� ����</param>
/// <param name="size">1���� �� �������� ��</param>
void AddPerson(int nextPerson, int size)
{
	// nextPerson�� 1���� �ִ´�.
	ateam[nextPerson] = true;

	// size�� 2/N�� ���ٸ� CalculateStats()�� ȣ���Ͽ� min�� ���� �� ���� ���� min�� �����ϰ� nextPerson�� 1������ ���� �Լ��� �����Ѵ�.
	if (size == N / 2)
	{
		min = std::min(min, CalculateStats());
		ateam[nextPerson] = false;
		return;
	}

	// size�� 2/N���� �۴ٸ� AddPerson�� �ٽ� �ѹ� ȣ���Ѵ�. nextPerson�� ���� ������ ū ���ں��� �ִ´�. size�� +1�Ѵ�.
	// size�� 2/N�� �ȵƴµ� nextPerson�� N�� ���ٸ� nextPerson�� 1������ ���� �Լ��� �����Ѵ�.
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

	// nextPerson�� 1������ ���� �Լ��� �����Ѵ�.
	ateam[nextPerson] = false;
	return;
}

int CalculateStats()
{
	int ateamStats = 0; // 1�� �ɷ�ġ
	int bteamStats = 0; // 2�� �ɷ�ġ

	// 1�� �ɷ�ġ ���
	// 2�� �ɷ�ġ ���
	for (int i = 1; i < N; i++)
	{
		if (ateam[i]) // 1�� �ɷ�ġ ���
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
		else // 2�� �ɷ�ġ ���
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

	// 1�� �ɷ�ġ - 2�� �ɷ�ġ
	// ����� ��ȯ, ������ -1 ���ؼ� ��ȯ
	if (ateamStats - bteamStats >= 0)
	{
		return ateamStats - bteamStats;
	}
	else
	{
		return bteamStats - ateamStats;
	}
}