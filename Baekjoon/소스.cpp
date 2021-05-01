#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> coordinate; //��ǥ
std::vector<int> order; //����

int main(void) 
{
	int n; //�Է¹��� ��ǥ�� ��
	int enter; //�Է°�

	//�� �Է�
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> enter;
		coordinate.push_back(enter);
		order.push_back(enter);
	}

	//order ���Ϳ��� �ߺ��� �����ϰ� �����Ѵ�.
	std::sort(order.begin(), order.end());
	order.erase(std::unique(order.begin(), order.end()), order.end());

	//���� ���
	//coordinate�迭�� �� ������ i�� �Ҵ��Ѵ�.
	//lower_bound �Լ��� ����� i�� order �迭�� �� ��°�� �����ϴ��� Ž���Ѵ�.
	//Ž���� ��ġ�� ����Ѵ�.
	int answer;
	for (int i : coordinate) 
	{
		answer = std::lower_bound(order.begin(), order.end(), i) - order.begin();
		std::cout << answer << " ";
	}
}