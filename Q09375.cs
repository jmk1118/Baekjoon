using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int T = Int32.Parse(input[0]);

        int N;
        int answer;
        Dictionary<string, int> clothes = new Dictionary<string, int>();
        for(int t = 0; t < T; t++)
        {
            input = Console.ReadLine().Split(" ");
            N = Int32.Parse(input[0]);
            clothes.Clear();

            for(int i = 0; i < N; i++)
            {
                input = Console.ReadLine().Split(" ");
                if (clothes.ContainsKey(input[1]) == false)
                {
                    clothes.Add(input[1], 0);
                }
                clothes[input[1]]++;
            }

            answer = 1;
            foreach(var i  in clothes)
            {
                answer *= i.Value + 1;
            }
            Console.WriteLine(answer - 1);
        }
    }
}