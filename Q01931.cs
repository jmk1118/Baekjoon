using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int N = Int32.Parse(Console.ReadLine());
        string[] input;
        List<KeyValuePair<int, int>> time = new List<KeyValuePair<int, int>>();

        for (int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split();
            time.Add(new KeyValuePair<int, int>(Int32.Parse(input[0]), Int32.Parse(input[1])));
        }
        time.Sort((x,y) => x.Key == y.Key ? x.Value.CompareTo(y.Value) : x.Key.CompareTo(y.Key)); // 시작 시간을 기준으로 정렬, 같다면 종료시간 순으로 정렬

        int answer = 1;
        int end = time[0].Value;
        for (int i = 1; i < time.Count; i++)
        {
            // 가장 마지막에 있던 회의보다 나중에 시작할경우 회의를 이어 시작할 수 있으므로 +1
            if (end <= time[i].Key) 
            {
                answer++;
                end = time[i].Value;
            }
            // 가장 마지막에 있던 회의보다 빨리 끝날경우 이 회의를 하는 편이 이득이므로 교체
            else if (time[i].Value < end)
            {
                end = time[i].Value;
            }
        }

        Console.WriteLine(answer);
    }
}