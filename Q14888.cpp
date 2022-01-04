#include <iostream>
#include <algorithm>

#define PLUS 1
#define MINUS 2
#define MULTI 3
#define DIV 4

int N; // 수열 수
int signNumber[5]; //1 : 덧셈, 2 : 뺄셈, 3 : 곱셈, 4 : 나눗셈
int number[12]; // 입력받은 수열
int sign[12]; // 백트래킹 함수에서 현재 부호들 상태를 저장할 배열, 덧셈 : 1, 뺄셈 : 2, 곱셈 : 3, 나눗셈 : 4
int max, min; // 답으로 제출할 최댓값, 최솟값

void EnterSign(int location); // 부호를 백트래킹하며 집어넣는 함수
int Calculation(); // 부호를 모두 채워넣었을 때 계산해줄 함수

int main(void)
{
	// 입력값 입력
	std::cin >> N;
	for (int i = 1; i <= N; i++)
		std::cin >> number[i];
	std::cin >> signNumber[1] >> signNumber[2] >> signNumber[3] >> signNumber[4];

	max = -1000000001;
	min = 1000000001;

	// 첫 칸부터 백트래킹
	sign[1] = PLUS; // 첫 숫자는 +나 마찬가지이므로 +로 초기화
	EnterSign(2);

	std::cout << max << std::endl;
	std::cout << min << std::endl;
}

void EnterSign(int location) // 부호를 백트래킹하며 집어넣는 함수
{
	for (int i = 1; i <= 4; i++)
	{
		// 덧셈, 뺼셈, 곱셈, 나눗셈 순서로 집어넣어본다. 단, 해당 부호가 남아있지 않다면 패스한다.
		if (signNumber[i] <= 0)
			continue;

		signNumber[i]--;
		sign[location] = i;

		// 모든 부호를 썻다면 계산하고 max와 min과 비교
		if (location == N)
		{
			int calculationNumber = Calculation(); // 계산식을 계산한 값
			max = std::max(max, calculationNumber);
			min = std::min(min, calculationNumber);
		}
		// 쓰지 않은 부호가 남아있다면 다음 location으로 진행
		else
			EnterSign(location + 1);
			
		// 돌아왔다면 넣었던 부호를 빼고 다시 진행
		signNumber[i]++;
		sign[location] = 0;
		
	}
}

int Calculation() // 부호를 모두 채워넣었을 때 계산해줄 함수
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