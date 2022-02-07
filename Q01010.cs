using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int T = Int32.Parse(input[0]);

        long[,] c = new long[30, 30];
        for (int i = 1; i <= 29; i++)
        {
            for (int p = 0; p <= i; p++) // k는 n의 값을 넘지 않는다
            {
                if (i == p || p == 0) // 전부 고르거나 전부 안고르면 경우의 수는 1
                {
                    c[i, p] = 1;
                }
                else
                {
                    c[i, p] = (c[i - 1, p - 1] + c[i - 1, p]);
                }
            }
        }

        int N, M;
        for(int i = 0; i < T; i++)
        {
            input = Console.ReadLine().Split(" ");
            N = Int32.Parse(input[0]);
            M = Int32.Parse(input[1]);

            Console.WriteLine(c[M, N]);
        }
    }
}