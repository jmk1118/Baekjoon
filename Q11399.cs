using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int answer = 0; // 답
        int N = Int32.Parse(Console.ReadLine()); // 기다리는 사람 수
        string[] input = Console.ReadLine().Split(" "); // 사람 별 필요시간

        List<int> people = new List<int>();
        foreach(string person in input)
        {
            people.Add(Int32.Parse(person));
        }
        people.Sort();

        int waitTime = 0; // 인출시점의 대기시간
        foreach(int person in people)
        {
            waitTime += person; // 대기시간에 인출할 사람의 필요시간을 더한다
            answer += waitTime; // 인출할 사람의 필요시간 + 인출 시점까지의 대기시간
        }

        Console.WriteLine(answer);
    }
}