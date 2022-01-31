using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int n = Int32.Parse(input[0]);
        int k = Int32.Parse(input[1]);

        int[,] c = new int[n + 1, n + 1];
        for(int i = 1; i <= n; i++)
        {
            for(int p = 0; p <= i; p++)
            {
                if (i == p || p == 0) 
                {
                    c[i, p] = 1;
                }
                else
                {
                    c[i, p] = (c[i - 1, p - 1] + c[i - 1, p]) % 10007;
                }
            }
        }

        Console.WriteLine(c[n, k]);
    }
}