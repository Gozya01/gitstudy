using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int b = 50;
            Person a = new Person(b);
            //a.Age = 10000;
            Console.WriteLine(a.Age);
        }
        public static int Getmax(int a, int b)
        {
            if (a > b) return a;
            return b;
        }
    }
}
