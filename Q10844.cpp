#include <iostream>

int main(void)
{
	int answer[101][10]; // 동적계획법용 배열
	int N; // 입력받은 '숫자의 길이'
	std::cin >> N; // 입력

	// 길이가 1일때의 값 초기화
	answer[1][0] = 0; 
	for (int i = 1; i <= 9; i++)
		answer[1][i] = 1;

	// 길이가 2 이상일 때의 값 계산
	// 길이가 n일 때, 0으로 끝나는 숫자는 n-1길이의 1로 끝나는 숫자와 갯수가 같다
	// 길이가 n일 때, 1~8로 끝나는 숫자는 n-1길이의 각 숫자의 -1과 +1로 끝나는 숫자와 갯수가 같다
	// 길이가 n일 때, 9로 끝나는 숫자는 n-1길이의 8로 끝나는 숫자와 갯수가 같다
	// 1000000000의 나머지가 답이므로, 1000000000을 넘으면 나머지만 계산해도 된다.
	for (int i = 2; i <= N; i++)
	{
		answer[i][0] = answer[i - 1][1];
		for (int o = 1; o <= 8; o++)
		{
			answer[i][o] = answer[i - 1][o - 1] + answer[i - 1][o + 1];
			if (answer[i][o] >= 1000000000)
				answer[i][o] = answer[i][o] % 1000000000;
		}
		answer[i][9] = answer[i - 1][8];
	}

	// N번째 배열의 합을 구한다
	// 1000000000을 넘으면 나머지만 다시 계산한다
	int sum = 0;
	for (int i = 0; i <= 9; i++)
	{
		sum += answer[N][i];
		if (sum >= 1000000000)
			sum = sum % 1000000000;
	}

	// 답 출력
	std::cout << sum;
}