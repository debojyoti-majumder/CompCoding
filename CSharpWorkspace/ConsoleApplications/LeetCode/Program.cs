using System;
using System.Collections.Generic;

namespace LeetCode
{
    class Program
    {
        static void tc1()
        {
            MyCalendarTwo c = new MyCalendarTwo();

            Console.WriteLine(c.Book(10, 20));      // returns true
            Console.WriteLine(c.Book(50, 60));      // returns true
            Console.WriteLine(c.Book(10, 40));      // returns true
            Console.WriteLine(c.Book(5, 15));       // returns false
            Console.WriteLine(c.Book(5, 10));       // returns true
            Console.WriteLine(c.Book(25, 55));      // returns true
        }

        static void Main(string[] args)
        {
            LargestPlusSign.TestCases();
        }
    }
}
