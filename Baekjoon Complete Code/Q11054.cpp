#include <iostream>
#include <vector>

int main(void)
{
	int N; // 입력할 수열의 수
	int number[1001]; // 입력받은 수열
	int length[1001]; // 각 index가 가장 높은 숫자일 떄의 바이토닉 수열의 길이
	std::vector<int> A; // size 계산용 벡터

	std::cin >> N;
	std::cin >> number[1];
	length[1] = 1;
	A.push_back(number[1]);

	// i까지의 올라가는 길이를 구해 length배열에 저장
	for (int i = 2; i <= N; i++)
	{
		std::cin >> number[i];
		if (number[i] > A.back())
		{
			A.push_back(number[i]);
			length[i] = A.size();
		}
		else
		{
			for (int o = 0; o < A.size(); o++)
			{
				if (A.at(o) >= number[i])
				{
					A.at(o) = number[i];
					length[i] = o + 1;
					break;
				}
			}
		}
	}

	// i부터 N까지의 내려가는 길이를 구해 length배열에 저장
	// N부터 i까지 올라가는 길이를 구하는 방식을 사용한다
	A.clear();
	A.push_back(number[N]);
	for (int i = N - 1; i >= 1; i--)
	{
		if (number[i] > A.back())
		{
			A.push_back(number[i]);
			length[i] += A.size() - 1;
		}
		else
		{
			for (int o = 0; o < A.size(); o++)
			{
				if (A.at(o) >= number[i])
				{
					A.at(o) = number[i];
					length[i] += o;
					break;
				}
			}
		}
	}

	// 가장 긴 길이를 찾아 출력
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (answer < length[i])
			answer = length[i];
	}
	std::cout << answer;
}