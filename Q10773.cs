using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int N = Int32.Parse(input[0]);
        Stack<int> stack = new Stack<int>();

        int x;
        for(int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split(" ");
            x = Int32.Parse(input[0]);

            if(x == 0)
            {
                stack.Pop();
            }
            else
            {
                stack.Push(x);
            }
        }

        long answer = 0;
        while(stack.Count > 0)
        {
            answer += stack.Pop();
        }
        Console.WriteLine(answer);
    }
}