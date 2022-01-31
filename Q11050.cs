using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int n = Int32.Parse(input[0]);
        int k = Int32.Parse(input[1]);

        int answer = Factorial(n) / (Factorial(k) * Factorial(n - k));

        Console.WriteLine(answer);
    }

    static int Factorial(int x)
    {
        int answer = 1;

        for(int i = 1; i <= x; i++)
        {
            answer *= i;
        }

        return answer;
    }
}