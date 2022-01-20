using System;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int N = Int32.Parse(input[0]);
        int a, b;
        int GCF; // 최대공약수
        for(int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split(" ");
            a = Int32.Parse(input[0]);
            b = Int32.Parse(input[1]);
            if(a > b) // b가 a보다 크도록 입력받는다
            {
                a = b;
                b = Int32.Parse(input[0]);
            }

            GCF = Euclidean(a, b); // 최대공약수
            // 최대공약수 * a를 최대공약수로 나눈 값 * b를 최대공약수로 나눈 값 = 최소공배수 
            Console.WriteLine(GCF * (a / GCF) * (b / GCF)); 
        }
    }

    // 유클리드 알고리즘
    static int Euclidean(int a, int b)
    {
        int r = b % a; // 큰 수를 작은 수로 나눈 나머지
        if (r == 0) // 나머지가 0이면 작은 수가 최대공약수
        {
            return a;
        }
        else // 나머지가 0이 아니면 나머지, 작은수를 인수로 유클리드 함수를 호출한다
        {
            return Euclidean(r, a);
        }
    }
}