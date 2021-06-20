#include <iostream>

int n; // 퀸의 수
bool chessboard[15][15]; // 체스판
int answer; // n개의 퀸을 놓을 수 있는 경우의 수
void DropTheQueen(int x, int y, int queenNum); // 퀸 놓기 함수

int main(void)
{
	std::cin >> n; // 퀸 숫자 입력
	answer = 0; // 답 초기화

	// 체스판 초기화
	for (int i = 0; i < n; i++) 
		for (int o = 0; o < n; o++)
			chessboard[i][o] = false;

	// n이 1이라면 칸이 하나뿐이므로 1을 출력하고 종료한다.
	if (n == 1) 
	{
		printf("1");
		return 0;
	}

	// n이 1 이상일 때 첫 퀸의 자리를 매개변수로 넣어 DropTheQueen 호출
	for (int i = 0; i < n; i++)
		DropTheQueen(0, i, 1);

	//답 출력
	printf("%d", answer);
}


void DropTheQueen(int x, int y, int queenNum)
{
	// 새로운 퀸의 좌우에 말이 없음을 확인
	for (int i = 0; i < x; i++) 
	{
		if (chessboard[i][y] == true)
			return;
	}

	// 새로운 퀸의 대각선에 말이 없음을 확인
	for (int i = 1; i <= x; i++)
	{
		if (y - i >= 0)
			if (chessboard[x - i][y - i] == true)
				return;

		if (y + i < n)
			if (chessboard[x - i][y + i] == true)
				return;
	}

	// 퀸의 숫자가 n이 되면 answer 1 증가
	if (queenNum == n)
	{
		answer = answer + 1;
		return;
	}

	// 퀸의 숫자가 n이 아니라면 새로운 퀸 두기
	chessboard[x][y] = true;

	// x, y 증가 순으로 배치하며, 같은 행(x)은 어차피 놓을 수 없으므로 다음 행부터 놓는다.
	for (int i = 0; i < n; i++)
		DropTheQueen(x + 1, i, queenNum + 1);

	// 자식들을 모두 돌아보면 퀸 회수하기
	chessboard[x][y] = false;
}