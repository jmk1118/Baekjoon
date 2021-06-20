#include <iostream>

int n; // ���� ��
bool chessboard[15][15]; // ü����
int answer; // n���� ���� ���� �� �ִ� ����� ��
void DropTheQueen(int x, int y, int queenNum); // �� ���� �Լ�

int main(void)
{
	std::cin >> n; // �� ���� �Է�
	answer = 0; // �� �ʱ�ȭ

	// ü���� �ʱ�ȭ
	for (int i = 0; i < n; i++) 
		for (int o = 0; o < n; o++)
			chessboard[i][o] = false;

	// n�� 1�̶�� ĭ�� �ϳ����̹Ƿ� 1�� ����ϰ� �����Ѵ�.
	if (n == 1) 
	{
		printf("1");
		return 0;
	}

	// n�� 1 �̻��� �� ù ���� �ڸ��� �Ű������� �־� DropTheQueen ȣ��
	for (int i = 0; i < n; i++)
		DropTheQueen(0, i, 1);

	//�� ���
	printf("%d", answer);
}


void DropTheQueen(int x, int y, int queenNum)
{
	// ���ο� ���� �¿쿡 ���� ������ Ȯ��
	for (int i = 0; i < x; i++) 
	{
		if (chessboard[i][y] == true)
			return;
	}

	// ���ο� ���� �밢���� ���� ������ Ȯ��
	for (int i = 1; i <= x; i++)
	{
		if (y - i >= 0)
			if (chessboard[x - i][y - i] == true)
				return;

		if (y + i < n)
			if (chessboard[x - i][y + i] == true)
				return;
	}

	// ���� ���ڰ� n�� �Ǹ� answer 1 ����
	if (queenNum == n)
	{
		answer = answer + 1;
		return;
	}

	// ���� ���ڰ� n�� �ƴ϶�� ���ο� �� �α�
	chessboard[x][y] = true;

	// x, y ���� ������ ��ġ�ϸ�, ���� ��(x)�� ������ ���� �� �����Ƿ� ���� ����� ���´�.
	for (int i = 0; i < n; i++)
		DropTheQueen(x + 1, i, queenNum + 1);

	// �ڽĵ��� ��� ���ƺ��� �� ȸ���ϱ�
	chessboard[x][y] = false;
}