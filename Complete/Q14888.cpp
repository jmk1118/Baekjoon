#include <iostream>
#include <algorithm>

#define PLUS 1
#define MINUS 2
#define MULTI 3
#define DIV 4

int N; // ���� ��
int signNumber[5]; //1 : ����, 2 : ����, 3 : ����, 4 : ������
int number[12]; // �Է¹��� ����
int sign[12]; // ��Ʈ��ŷ �Լ����� ���� ��ȣ�� ���¸� ������ �迭, ���� : 1, ���� : 2, ���� : 3, ������ : 4
int max, min; // ������ ������ �ִ�, �ּڰ�

void EnterSign(int location); // ��ȣ�� ��Ʈ��ŷ�ϸ� ����ִ� �Լ�
int Calculation(); // ��ȣ�� ��� ä���־��� �� ������� �Լ�

int main(void)
{
	// �Է°� �Է�
	std::cin >> N;
	for (int i = 1; i <= N; i++)
		std::cin >> number[i];
	std::cin >> signNumber[1] >> signNumber[2] >> signNumber[3] >> signNumber[4];

	max = -1000000001;
	min = 1000000001;

	// ù ĭ���� ��Ʈ��ŷ
	sign[1] = PLUS; // ù ���ڴ� +�� ���������̹Ƿ� +�� �ʱ�ȭ
	EnterSign(2);

	std::cout << max << std::endl;
	std::cout << min << std::endl;
}

void EnterSign(int location) // ��ȣ�� ��Ʈ��ŷ�ϸ� ����ִ� �Լ�
{
	for (int i = 1; i <= 4; i++)
	{
		// ����, �E��, ����, ������ ������ ����־��. ��, �ش� ��ȣ�� �������� �ʴٸ� �н��Ѵ�.
		if (signNumber[i] <= 0)
			continue;

		signNumber[i]--;
		sign[location] = i;

		// ��� ��ȣ�� ���ٸ� ����ϰ� max�� min�� ��
		if (location == N)
		{
			int calculationNumber = Calculation(); // ������ ����� ��
			max = std::max(max, calculationNumber);
			min = std::min(min, calculationNumber);
		}
		// ���� ���� ��ȣ�� �����ִٸ� ���� location���� ����
		else
			EnterSign(location + 1);
			
		// ���ƿԴٸ� �־��� ��ȣ�� ���� �ٽ� ����
		signNumber[i]++;
		sign[location] = 0;
		
	}
}

int Calculation() // ��ȣ�� ��� ä���־��� �� ������� �Լ�
{
	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		switch (sign[i])
		{
			case 1:
				answer += number[i];
				break;
			case 2:
				answer -= number[i];
				break;
			case 3:
				answer *= number[i];
				break;
			case 4:
				answer /= number[i];
				break;
		}
	}

	return answer;
}