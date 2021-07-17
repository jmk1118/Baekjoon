#include <iostream>

int sumFibonacci[41][2]; // 동적계획법에 사용하는 N당 0과 1의 출력 횟수 저장용 배열

int main(void)
{
    int T, N; // 문제에서 입력받은 수
    
    std::cin >> T;

    // 0의 출력횟수와 1의 출력 횟수를 피보나치 40까지 미리 연산해놓는다. 
    // 피보나치 n의 출력횟수는 피보나치 n-1과 피보나치 n-2의 합과 같다.
    sumFibonacci[0][0] = 1;
    sumFibonacci[0][1] = 0;
    sumFibonacci[1][0] = 0;
    sumFibonacci[1][1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        sumFibonacci[i][0] = sumFibonacci[i - 1][0] + sumFibonacci[i - 2][0];
        sumFibonacci[i][1] = sumFibonacci[i - 1][1] + sumFibonacci[i - 2][1];
    }

    // 답을 출력한다.
    for (int i = 1; i <= T; i++)
    {
        std::cin >> N;
        std::cout << sumFibonacci[N][0] << " " << sumFibonacci[N][1] << std::endl;
    }
}