using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        long N = Int32.Parse(input[0]);
        long M = Int32.Parse(input[1]);

        long two = HowManyTwo(N) - HowManyTwo(M) - HowManyTwo(N - M);
        long five = HowManyFive(N) - HowManyFive(M) - HowManyFive(N - M);

        Console.WriteLine(Math.Min(two, five));
    }

    static long HowManyTwo(long x)
    {
        long answer = 0;
        while(x >= 2)
        {
            answer += x / 2;
            x /= 2;
        }
        return answer;
    }
    
    static long HowManyFive(long x)
    {
        long answer = 0;
        while(x >= 5)
        {
            answer += x / 5;
            x /= 5;
        }
        return answer;
    }
}