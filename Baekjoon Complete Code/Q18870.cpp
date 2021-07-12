#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> coordinate; //좌표
std::vector<int> order; //순서

int main(void) 
{
	int n; //입력받을 좌표의 수
	int enter; //입력값

	//값 입력
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> enter;
		coordinate.push_back(enter);
		order.push_back(enter);
	}

	//order 벡터에서 중복을 제거하고 정렬한다.
	std::sort(order.begin(), order.end());
	order.erase(std::unique(order.begin(), order.end()), order.end());

	//정답 출력
	//coordinate배열의 각 값들을 i에 할당한다.
	//lower_bound 함수를 사용해 i가 order 배열의 몇 번째에 존재하는지 탐색한다.
	//탐색한 위치를 출력한다.
	int answer;
	for (int i : coordinate) 
	{
		answer = std::lower_bound(order.begin(), order.end(), i) - order.begin();
		std::cout << answer << " ";
	}
}