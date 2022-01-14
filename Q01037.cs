using System;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int N = Int32.Parse(input[0]);

        input = Console.ReadLine().Split(" ");
        int[] divisors = new int[input.Length];
        for (int i = 0; i < input.Length; i++)
        {
            divisors[i] = Int32.Parse(input[i]);
        }

        Array.Sort(divisors);

        Console.WriteLine(divisors[0] * divisors[divisors.Length - 1]);
    }
}