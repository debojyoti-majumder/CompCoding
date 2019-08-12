using System;
using System.Text;

// Problem URL: https://leetcode.com/problems/push-dominoes/

namespace PushDominos
{
    public class Solution
    {
        private StringBuilder _outputString;

        private bool IsToBeAltered(bool isLeft, int index)
        {
            if (isLeft)
            {
                if (index == 0) return false;
                else return _outputString[index - 1] != 'L';
            }
            else
            {
                if (index == _outputString.Length - 1) return false;
                else return _outputString[index + 1] != 'R';
            }
        }

        private bool CanStandStill(int index)
        {
            if (_outputString[index] != '.') return false;

            if (index == 0 || index == _outputString.Length) return false;
            else return _outputString[index - 1] == 'R' && _outputString[index + 1] == 'L';
        }

        public string PushDominoes(string dominoes)
        {
            _outputString = new StringBuilder(dominoes);

            for (int i = 0; i < _outputString.Length; i++)
            {
                if (CanStandStill(i))
                    continue;

                if (dominoes[i] == 'L' && IsToBeAltered(true, i))
                {
                    _outputString[i - 1] = 'L';
                }
                else if (dominoes[i] == 'R' && IsToBeAltered(false, i))
                {
                    _outputString[i + 1] = 'R';
                }
            }

            var processedString = _outputString.ToString();
            if (processedString == dominoes)
                return processedString;

            return PushDominoes(processedString);
        }

        public static void TestCases()
        {
            PushDominos.Solution s = new PushDominos.Solution();

            // Should ouput "LL.RR.LLRRLL.."
            Console.WriteLine(s.PushDominoes(".L.R...LR..L.."));

            // Should output "RR.L"
            Console.WriteLine(s.PushDominoes("RR.L"));

        }
    }

}
