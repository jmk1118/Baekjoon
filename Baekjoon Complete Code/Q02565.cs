using System;
using System.Collections.Generic;

class MainApp
{
    static void Main(string[] args)
    {
        int N = Int32.Parse(Console.ReadLine()); // 입력수 입력

        // 입력값 입력
        int[] line = new int[501];
        string[] startend = new string[2];
        for (int i = 0; i < N; i++) 
        {
            startend = Console.ReadLine().Split(" ");
            line[Int32.Parse(startend[0])] = Int32.Parse(startend[1]);
        }

        // 증가하는 부분 수열 탐색
        List<int> useLine = new List<int>();
        foreach(int end in line)
        {
            if (end == 0)
            {
                continue;
            }
            if (useLine.Count == 0 || useLine[useLine.Count - 1] < end)
            {
                useLine.Add(end);
            }
            else
            {
                for(int i = 0; i < useLine.Count; i++)
                {
                    if (useLine[i] > end)
                    {
                        useLine[i] = end;
                        break;
                    }
                }
            }
        }

        Console.WriteLine(N - useLine.Count);
    }
}