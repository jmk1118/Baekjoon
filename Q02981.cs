using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int N = Int32.Parse(input[0]);
        
        List<int> numbers = new List<int>();
        for(int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split(" ");
            numbers.Add(Int32.Parse(input[0]));
        }
        numbers.Sort(); // 큰 숫자에서 작은 숫자를 빼기 위해 정렬

        int gcf = numbers[1] - numbers[0]; // 최대공약수
        // a,b,c가 있을 때, b-a와 c-b의 최대공약수를 구한다
        for(int i = 2; i < N; i++)
        {
            gcf = Euclidean(gcf, numbers[i] - numbers[i - 1]);
        }

        // 최대 공약수의 모든 약수를 1을 제외하고 출력한다
        for(int i = 2; i <= gcf; i++)
        {
            if (gcf % i == 0)
                Console.Write(i.ToString() + " ");
        }
    }

    // 유클리드 알고리즘
    static int Euclidean(int a, int b)
    {
        int r; // a를 b로 나눈 나머지

        // b가 0이 될때까지 반복한다
        // b가 0이 아니라면 a,b를 b,r로 갱신해 반복한다
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }

        return a; // 최대공약수
    }
}