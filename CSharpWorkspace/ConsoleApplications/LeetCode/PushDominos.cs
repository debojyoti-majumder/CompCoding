﻿using System.Text;

// Problem URL: https://leetcode.com/problems/push-dominoes/

namespace PushDominos
{
    public class Solution
    {
        private StringBuilder _outputString;
        
        private bool IsToBeAltered(bool isLeft, int index)
        {
            if( isLeft )
            {
                if (index == 0) return false;
                else return _outputString[index - 1] == '.';
            }
            else {
                if (index == _outputString.Length - 1) return false;
                else return _outputString[index + 1] == '.';
            }
        }

        private bool CanStandStill(int index)
        {
            if (index == 0 || index == _outputString.Length) return false;
            else return false; 
        }

        public string PushDominoes(string dominoes)
        {
            bool isChangesMade = false;
            _outputString = new StringBuilder(dominoes);

            for(int i=0; i<_outputString.Length; i++)
            {

                if( dominoes[i] == 'L' && IsToBeAltered(true, i) )
                {
                    if (isChangesMade == false)
                        isChangesMade = true;

                    _outputString[i - 1] = 'L';
                    
                }
                else if ( dominoes[i] == 'R' && IsToBeAltered(false, i))
                {

                    if (isChangesMade == false)
                        isChangesMade = true;

                    _outputString[i+1] = 'R';
                }
            }

            var processedString = _outputString.ToString();
            if (isChangesMade == false)
                return processedString;

            return PushDominoes(processedString);
        }
    }
}
