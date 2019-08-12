// Problem URL: https://leetcode.com/problems/largest-plus-sign/
// Related Problem: https://leetcode.com/problems/maximal-rectangle/
// Related Problem: https://leetcode.com/problems/maximal-square/

using System;
using System.Collections.Generic;

namespace LeetCode
{
    class LargestPlusSign
    {
        private List<List<int>> NumberMatrix;

        public LargestPlusSign()
        {
            NumberMatrix = new List<List<int>>();
        }

        public int OrderOfLargestPlusSign(int N, int[][] mines)
        {
            NumberMatrix.Clear();

            // Constructing the matrix
            List<int> row = new List<int>(N);
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    row.Add(i);

                NumberMatrix.Add(row);
            }
            
            return 0;
        }

        public static void TestCases()
        {
            LargestPlusSign pl = new LargestPlusSign();
            int[][] mines = new int[][]
            {
                new int[] {4,2}
            };

            Console.WriteLine(pl.OrderOfLargestPlusSign(5,mines));
        }
    }
}
