#include <iostream>
#include <vector>

int sudoku[10][10]; // 스도쿠
std::vector<std::pair<int, int>> location;// 0을 가진 좌표를 기록해놓는 배열

bool EraseSudokuEmpty(int locationNum); // 0을 가진 좌표에 임의의 값을 집어넣는 백트래킹 함수

int main(void)
{
	// 문제 입력
	for (int i = 1; i < 10; i++)
		for (int o = 1; o < 10; o++)
		{
			std::cin >> sudoku[i][o];

			// 0을 입력받으면 0을 가진 좌표 배열에 추가
			if (sudoku[i][o] == 0)
				location.push_back(std::make_pair(i, o));
		}
	
	// 백트래킹을 사용하여 탐색
	for (int i = 0; i < location.size(); i++)
		if (EraseSudokuEmpty(i))
			break;

	// 답 출력
	for (int i = 1; i < 10; i++)
	{
		for (int o = 1; o < 10; o++)
			printf("%d ", sudoku[i][o]);
		printf("\n");
	}
}

/// <summary>
/// 0 좌표에 임의의 값을 집어넣고 백트래킹 하는 함수
/// </summary>
/// <param name="locationNum">0을 가진 좌표 배열의 몇번째 칸인지 알려주는 변수</param>
bool EraseSudokuEmpty(int locationNum)
{
	// 1 ~ 9가 가로, 세로, 같은 칸에 있는지 확인하기 위해 불린 배열 선언
	bool number[10];
	for (int i = 0; i < 10; i++) // 배열 초기화
		number[i] = false;

	// 넣을 수 있는 후보 추리기
	for (int i = 1; i < 10; i++)
	{
		number[sudoku[i][location.at(locationNum).second]] = true; // 가로 확인
		number[sudoku[location.at(locationNum).first][i]] = true; // 세로 확인
	}
	// 같은 칸 확인
	for (int i = ((location.at(locationNum).first - 1) / 3) * 3 + 1; i <= ((location.at(locationNum).first - 1) / 3) * 3 + 3; i++)
		for (int o = ((location.at(locationNum).second - 1) / 3) * 3 + 1; o <= ((location.at(locationNum).second - 1) / 3) * 3 + 3; o++)
			number[sudoku[i][o]] = true;

	// 넣을 수 있는 후보들을 각각 넣어보고 다음 0 좌표에 EraseSudokuEmpty 호출
	for (int i = 1; i < 10; i++)
	{
		if (number[i]) // 가로, 세로, 같은 칸에 없는 숫자들만 백트래킹 실행
			continue;
		else 
		{
			// 넣을 수 있는 숫자 중 하나를 입력
			sudoku[location.at(locationNum).first][location.at(locationNum).second] = i;
			// 더이상 0인 좌표가 없다면 정답이므로 백트래킹 탈출
			if (locationNum == location.size() - 1)
				return true;
			// 0인 좌표가 남아있다면 다음 0인 좌표로 백트래킹 함수 호출
			if (locationNum < location.size() - 1)
				if (EraseSudokuEmpty(locationNum + 1)) // 백트래킹하여 정답이 나왔을 경우 백트래킹 탈출
					return true;
			// 백트래킹하여 정답이 나오지 않았을 경우 입력했던 숫자를 다시 0으로 변환
			sudoku[location.at(locationNum).first][location.at(locationNum).second] = 0;
		}
	}

	return false; // 정답에 다다를 수 없었으므로 이전 좌표로 귀환
}