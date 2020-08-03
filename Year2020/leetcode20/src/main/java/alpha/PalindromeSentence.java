/*
* Problem URL: https://leetcode.com/problems/valid-palindrome/
* Status: Accepted
* Difficulty: Easy
* Problem ID: 125
* */

package alpha;

public class PalindromeSentence {
    public boolean isPalindrome(String s) {
        boolean retValue = true;

        // This would be used as a cursor
        int startIndex = 0;
        int endIndex = s.length() - 1;

        while( startIndex <= endIndex  ) {
            char leftChar = Character.toUpperCase(s.charAt(startIndex));
            char rightChar = Character.toUpperCase(s.charAt(endIndex));

            // Test for alpha numeric character, they are to be skipped
            if( !Character.isAlphabetic(leftChar) && !Character.isDigit(leftChar) ) {
                startIndex++;
                continue;
            }

            if( !Character.isAlphabetic(rightChar) && !Character.isDigit(rightChar) ) {
                endIndex--;
                continue;
            }

            if( leftChar != rightChar ) {
                retValue = false;
                break;
            }

            startIndex++;
            endIndex--;
        }

        return retValue;
    }
}
