#include <iostream>

int n, m; // ������ �ִ񰪰� ������ ����
int answer[9]; // ���ǿ� �´� ������ �����ϴ� �迭

void backTracking(int nowlength, int value); // ��Ʈ��ŷ�� �ϴ� DFS �Լ�

int main(void) 
{
	std::cin >> n >> m; // n, m �Է�

	// ù ��° ���� �Է��ϰ� ��Ʈ��ŷ �Լ��� �����Ѵ�. 
	// ù ��° ���� 1���� n - m + 1������ �Էµ� �� �ִ�. m��ŭ�� ���̰� ��µǾ� �ϱ� �����̴�.
	for (int i = 1; i <= n - m + 1; i++)
	{
		answer[1] = i;
		if (m == 1) // ���� ������ ���̰� 1�̶�� ��Ʈ��ŷ�� ������ �ʰ� �״�� ����Ѵ�.
		{
			std::cout << answer[1] << std::endl;
			continue;
		}

		for (int o = i + 1; o <= n; o++) // ������ ���������̹Ƿ� ù ��° ���� �Է��� ������ ū ���� ���ʴ�� ��Ʈ��ŷ �Լ��� �Է��Ѵ�.
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
			std::cout << answer[i] << " ";
		std::cout << std::endl;

		return;
	}

	for (int i = value + 1; i <= n; i++) // ������ ���������̹Ƿ� ù ��° ���� �Է��� ������ ū ���� ���ʴ�� ��Ʈ��ŷ �Լ��� �Է��Ѵ�.
	{
		backTracking(nowlength + 1, i);
	}
}