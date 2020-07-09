// Problem URL: https://www.codewars.com/kata/50654ddff44f800200000004/train/csharp

using NUnit.Framework;
using System;

namespace Part1
{
    public class CustomMath
    {
        public static int Multiply(int a, int b)
        {
            return a * b;
        }

        [TestFixture]
        public class TestCases
        {
            [Test]
            public void SimpleTest()
            {
                Assert.AreEqual(6, Multiply(2, 3));
                Assert.AreEqual(0, Multiply(0, 6));
            }

            [Test]
            public void BasicPropertytest()
            {
                var generator = new Random();

                for( int i=0; i<10; i++ )
                {
                    int data = generator.Next();
                    Assert.AreEqual(0, Multiply(0, data));
                    Assert.AreEqual(data, Multiply(1, data));
                }
            }
        }
    }
}
