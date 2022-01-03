using System;

namespace BaekjoonCS
{
    class Program
    {
        static void Main(string[] args)
        {
            int answer = 0; // 정답을 저장할 변수
            string first = " " + Console.ReadLine(); // 입력할 첫 문장
            string second = " " + Console.ReadLine(); // 입력할 두번째 문장
            int[,] table = new int[first.Length, second.Length]; // LCS를 구하기 위한 표
            
            for(int i = 0; i < first.Length; i++)
            {
                for(int o = 0; o < second.Length; o++)
                {
                    // 초기 길이로 0을 넣는다
                    if (i == 0 || o == 0)
                    {
                        table[i, o] = 0;
                        continue;
                    }
                    // 같은 글자가 나왔을 때 직전 문자까지의 LCS에서 +1한다
                    else if (first[i] == second[o])
                    {
                        table[i, o] = table[i - 1, o - 1] + 1;
                        if (answer < table[i, o])
                            answer = table[i, o];
                    }
                    // 같은 글자가 아니라면 이전 문자들 중 가장 긴 LCS를 가져온다
                    else
                    {
                        table[i, o] = Math.Max(table[i - 1, o], table[i, o - 1]);
                    }
                }
            }

            Console.WriteLine(answer);
        }
    }
}