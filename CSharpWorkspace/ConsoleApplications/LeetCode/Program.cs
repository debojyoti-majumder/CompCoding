using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    class Program
    {
        static void Main(string[] args)
        {
            PushDominos.Solution s = new PushDominos.Solution();

            // Should ouput "LL.RR.LLRRLL.."
            Console.WriteLine(s.PushDominoes(".L.R...LR..L.."));

            // Should output "RR.L"
            Console.WriteLine(s.PushDominoes("RR.L"));
        }
    }
}
