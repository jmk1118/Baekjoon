#include <iostream>

int n, m; // ������ �ִ񰪰� ������ ����
int answer[9]; // ���ǿ� �´� ������ �����ϴ� �迭

void backTracking(int nowlength, int value); // ��Ʈ��ŷ�� �ϴ� DFS �Լ�

int main(void)
{
	std::cin >> n >> m; // n, m �Է�

	// ù ��° ���� �Է��ϰ� ��Ʈ��ŷ �Լ��� �����Ѵ�. 
	// ù ��° ���� 1���� n���� �����Ѵ�.
	for (int i = 1; i <= n; i++)
	{
		answer[1] = i;
		if (m == 1) // ���� ������ ���̰� 1�̶�� ��Ʈ��ŷ�� ������ �ʰ� �״�� ����Ѵ�.
		{
			printf("%d\n", answer[1]);
			continue;
		}

		for (int o = 1; o <= n; o++) // ���� ���� ������ ��� �������Ƿ� 1���� n���� ��� ���ڸ� ��Ʈ��ŷ�Ѵ�.
			backTracking(2, o);
	}
}

/// <summary>
/// ��Ʈ��ŷ �Լ�
/// </summary>
/// <param name="nowlength">���� �Լ����� �Է��� ������ ��ġ</param>
/// <param name="value">���� �Լ����� ������ �Է��� ��</param>
void backTracking(int nowlength, int value)
{
	answer[nowlength] = value; // �Է¹��� ��ġ�� �Է¹��� ���� ����ִ´�.

	if (nowlength >= m) // �Է¹��� ���鿡 ���� ������ ���̰� m�� �Ǿ��ٸ� ������ ����ϰ� �θ� ���� ���ư���.
	{
		for (int i = 1; i <= m; i++)
			printf("%d ", answer[i]);
		printf("\n");

		return;
	}

	for (int i = 1; i <= n; i++) // ���� ���� ������ ��� �������Ƿ� 1���� n���� ��� ���ڸ� ��Ʈ��ŷ�Ѵ�.
	{
		backTracking(nowlength + 1, i);
	}
}