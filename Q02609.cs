using System;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int A = Int32.Parse(input[0]);
        int B = Int32.Parse(input[1]);
        if (A > B)
        {
            A = B;
            B = Int32.Parse(input[0]);
        }

        int answerone = 0;
        int answertwo = 0;

        for (int i = 1; i <= B; i++)
        {
            if (i <= A)
            {
                if(A % i == 0 && B % i == 0)
                {
                    answerone = i;
                }
            }
            if ((A * i) % B == 0 && answertwo == 0)
            {
                answertwo = A * i;
            }
        }

        Console.WriteLine(answerone);
        Console.WriteLine(answertwo);
    }
}