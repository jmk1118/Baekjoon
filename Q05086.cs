using System;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(" ");
        int front = Int32.Parse(input[0]);
        int back = Int32.Parse(input[1]);
        
        while (front != 0 || back != 0)
        {
            if (back % front == 0)
            {
                Console.WriteLine("factor");
            }
            else if (front % back == 0)
            {
                Console.WriteLine("multiple");
            }
            else
            {
                Console.WriteLine("neither");
            }

            input = Console.ReadLine().Split(" ");
            front = Int32.Parse(input[0]);
            back = Int32.Parse(input[1]);
        }
    }
}