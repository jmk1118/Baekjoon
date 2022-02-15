using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int A = Int32.Parse(input[0]);
        int B = Int32.Parse(input[1]);
        input = Console.ReadLine().Split(" ");
        int C = Int32.Parse(input[0]);

        int answer = A * 60 + B + C;
        if(answer / (24 * 60) > 0)
        {
            answer = answer % (24 * 60);
        }
        Console.WriteLine(answer / 60 + " " + answer % 60);
    }
}