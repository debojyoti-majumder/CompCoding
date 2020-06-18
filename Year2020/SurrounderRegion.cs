// Problem URL: https://leetcode.com/problems/surrounded-regions/

using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;

namespace LeetcodeSolutions
{
    [TestFixture]
    class SurrounderRegion
    {
        private char[][] GameBoard;

        private bool IsBorder(int i, int j )
        {
            if (i == 0 || j == 0) return true;
            else if (i == GameBoard.Length - 1 || j == GameBoard[i].Length - 1) return true;
            else return false;
        }

        private bool IsSurrounded(int i, int j)
        {
            if (GameBoard[i][j] == 'X') return false;

            if( GameBoard[i - 1][j] == 'X' && 
                GameBoard[i + 1][j] == 'X' &&
                GameBoard[i][j - 1] == 'X')
            {
                return true;
            }

            return false;
        }

        public void Solve(char[][] board)
        {
            GameBoard = board;

            for( int rowIndex=0; rowIndex<board.Length; rowIndex++ )
            {
                for(int colIndex=0; colIndex<board[rowIndex].Length; colIndex++ )
                {
                    // We are not processing the edges
                    if (IsBorder(rowIndex, colIndex)) continue;

                    // Replacing the surrounded item
                    char boardItem = GameBoard[rowIndex][colIndex];
                    if (boardItem == 'O' && IsSurrounded(rowIndex, colIndex)) GameBoard[rowIndex][colIndex] = 'X';
                }
            }
        }
        
        [Test]
        public void BasicTest()
        {
            char[][] input =
            {
                new char[] { 'X', 'X', 'X', 'X' },
                new char[] { 'X', 'O', 'O', 'X' },
                new char[] { 'X', 'X', 'O', 'X' },
                new char[] { 'X', 'O', 'X', 'X' }
            };

            char[][] output =
            {
                new char[] { 'X', 'X', 'X', 'X' },
                new char[] { 'X', 'X', 'X', 'X' },
                new char[] { 'X', 'X', 'X', 'X' },
                new char[] { 'X', '0', 'X', 'X' }
            };

            SurrounderRegion region = new SurrounderRegion();
            region.Solve(input);
            Assert.AreEqual(input, output);
        }
    }
}
