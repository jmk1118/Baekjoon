#include <iostream>
#include <vector>

int sudoku[10][10]; // ������
std::vector<std::pair<int, int>> location;// 0�� ���� ��ǥ�� ����س��� �迭

bool EraseSudokuEmpty(int locationNum); // 0�� ���� ��ǥ�� ������ ���� ����ִ� ��Ʈ��ŷ �Լ�

int main(void)
{
	// ���� �Է�
	for (int i = 1; i < 10; i++)
		for (int o = 1; o < 10; o++)
		{
			std::cin >> sudoku[i][o];

			// 0�� �Է¹����� 0�� ���� ��ǥ �迭�� �߰�
			if (sudoku[i][o] == 0)
				location.push_back(std::make_pair(i, o));
		}
	
	// ��Ʈ��ŷ�� ����Ͽ� Ž��
	for (int i = 0; i < location.size(); i++)
		if (EraseSudokuEmpty(i))
			break;

	// �� ���
	for (int i = 1; i < 10; i++)
	{
		for (int o = 1; o < 10; o++)
			printf("%d ", sudoku[i][o]);
		printf("\n");
	}
}

/// <summary>
/// 0 ��ǥ�� ������ ���� ����ְ� ��Ʈ��ŷ �ϴ� �Լ�
/// </summary>
/// <param name="locationNum">0�� ���� ��ǥ �迭�� ���° ĭ���� �˷��ִ� ����</param>
bool EraseSudokuEmpty(int locationNum)
{
	// 1 ~ 9�� ����, ����, ���� ĭ�� �ִ��� Ȯ���ϱ� ���� �Ҹ� �迭 ����
	bool number[10];
	for (int i = 0; i < 10; i++) // �迭 �ʱ�ȭ
		number[i] = false;

	// ���� �� �ִ� �ĺ� �߸���
	for (int i = 1; i < 10; i++)
	{
		number[sudoku[i][location.at(locationNum).second]] = true; // ���� Ȯ��
		number[sudoku[location.at(locationNum).first][i]] = true; // ���� Ȯ��
	}
	// ���� ĭ Ȯ��
	for (int i = ((location.at(locationNum).first - 1) / 3) * 3 + 1; i <= ((location.at(locationNum).first - 1) / 3) * 3 + 3; i++)
		for (int o = ((location.at(locationNum).second - 1) / 3) * 3 + 1; o <= ((location.at(locationNum).second - 1) / 3) * 3 + 3; o++)
			number[sudoku[i][o]] = true;

	// ���� �� �ִ� �ĺ����� ���� �־�� ���� 0 ��ǥ�� EraseSudokuEmpty ȣ��
	for (int i = 1; i < 10; i++)
	{
		if (number[i]) // ����, ����, ���� ĭ�� ���� ���ڵ鸸 ��Ʈ��ŷ ����
			continue;
		else 
		{
			// ���� �� �ִ� ���� �� �ϳ��� �Է�
			sudoku[location.at(locationNum).first][location.at(locationNum).second] = i;
			// ���̻� 0�� ��ǥ�� ���ٸ� �����̹Ƿ� ��Ʈ��ŷ Ż��
			if (locationNum == location.size() - 1)
				return true;
			// 0�� ��ǥ�� �����ִٸ� ���� 0�� ��ǥ�� ��Ʈ��ŷ �Լ� ȣ��
			if (locationNum < location.size() - 1)
				if (EraseSudokuEmpty(locationNum + 1)) // ��Ʈ��ŷ�Ͽ� ������ ������ ��� ��Ʈ��ŷ Ż��
					return true;
			// ��Ʈ��ŷ�Ͽ� ������ ������ �ʾ��� ��� �Է��ߴ� ���ڸ� �ٽ� 0���� ��ȯ
			sudoku[location.at(locationNum).first][location.at(locationNum).second] = 0;
		}
	}

	return false; // ���信 �ٴٸ� �� �������Ƿ� ���� ��ǥ�� ��ȯ
}