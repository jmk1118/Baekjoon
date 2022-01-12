using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        long answer = 0; // 답
        int N = Int32.Parse(Console.ReadLine()); // 도시의 수
        long nowPrice; // answer가 long이므로 long 계산용으로 long 할당

        List<int> distance = new List<int>(); // 도시 간 거리
        string[] input = Console.ReadLine().Split(" ");
        foreach(string dis in input)
        {
            distance.Add(Int32.Parse(dis));
        }

        List<int> price = new List<int>(); // 도시 별 기름값
        input = Console.ReadLine().Split(" ");
        foreach(string pri in input)
        {
            price.Add(Int32.Parse(pri));
        }

        nowPrice = price[0]; // 지나온 도시 중 가장 싼 기름값
        for(int i = 1; i < price.Count; i++)
        {
            // 이전 도시와 현재 도시 사이의 거리를 지금까지 중 가장 싼 기름값으로 계산
            answer += nowPrice * distance[i - 1];
            
            // 현재 도시가 지나온 도시들보다 기름값이 싸다면 가장 싼 기름값을 갱신
            if (price[i] < nowPrice) 
            {
                nowPrice = price[i]; 
            }
        }

        Console.WriteLine(answer);
    }
}