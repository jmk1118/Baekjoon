using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int N = Int32.Parse(input[0]);

        input = Console.ReadLine().Split(" ");
        List<int> numbers = new List<int>();
        for(int i = 0; i < N; i++)
        {
            numbers.Add(Int32.Parse(input[i]));
        }

        int gcf;
        for(int i = 1; i < N; i++)
        {
            gcf = Euclidean(numbers[0], numbers[i]);
            Console.WriteLine((numbers[0] / gcf).ToString() + "/" + (numbers[i] / gcf).ToString());
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