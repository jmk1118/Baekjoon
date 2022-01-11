using System;

class Program
{
    static void Main(string[] args)
    {
        string input = Console.ReadLine();
        string[] splitForMinus = input.Split("-"); // -를 기준으로 파트를 나눈다
        
        int answer = addPart(splitForMinus[0]); // 첫 파트를 답에 더해준다
        for(int i = 1; i < splitForMinus.Length; i++)
        {
            answer -= addPart(splitForMinus[i]); // 나머지 파트를 답에서 뺴준다
        }

        Console.WriteLine(answer);
    }

    // -로 나눈 파트안에 있는 +들을 계산하는 메소드
    static int addPart(string part)
    {
        string[] splitForPlus = part.Split("+");
        int partSum = 0;
        foreach(var num in splitForPlus)
        {
            partSum += Int32.Parse(num);
        }

        return partSum;
    }
}