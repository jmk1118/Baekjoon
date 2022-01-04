using System;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int N = Int32.Parse(input[0]); // 물건 수
        int K = Int32.Parse(input[1]); // 배낭 최대 용량
        int W, V; // 물건의 무게, 물건의 가치
        int[,] weight = new int[N + 1, K + 1];

        for (int i = 1; i <= N; i++)
        {
            input = Console.ReadLine().Split(" ");
            W = Int32.Parse(input[0]);
            V = Int32.Parse(input[1]);

            for (int o = 1; o <= K; o++)
            {
                // o(가정한 배낭 용량)보다 W(현재 물건의 무게)가 크다면 넣을 수 없으므로 현재 물건을 넣지 않은 무게를 저장
                if (o < W)
                {
                    weight[i, o] = weight[i - 1, o];
                }
                // 현재 물건을 넣는 경우와 넣지 않는 경우 중 더 가치가 높은 것을 저장
                else
                {
                    weight[i, o] = Math.Max(weight[i - 1, o], weight[i - 1, o - W] + V);
                }
            }
        }

        Console.WriteLine(weight[N, K]);
    }
}