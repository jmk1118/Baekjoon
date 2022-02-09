using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int N = Int32.Parse(input[0]);

        int two = 0;
        int five = 0;
        int now;
        for (int i = 1; i <= N; i++) 
        {
            now = i;
            while (now % 2 == 0)
            {
                two++;
                now /= 2;
            }
            while (now % 5 == 0)
            {
                five++;
                now /= 5;
            }
        }
        if (two < five)
            Console.WriteLine(two);
        else
            Console.WriteLine(five);
    }
}