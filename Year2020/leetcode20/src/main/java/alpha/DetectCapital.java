/*
* Problem URL: https://leetcode.com/problems/detect-capital/
* Problem ID: 520
* Status: Accepted
* Difficulty: Easy
*/

package alpha;

public class DetectCapital {
    private String wordToBeChecked;

    private boolean performCheck(boolean isFirstLetterBig) {
        boolean retValue = true;
        boolean allSmallIsRequired = false;

        // Starting from 1 as the first letter is already checked
        for( int i=1; i < wordToBeChecked.length(); i++ ) {
            char testChar = wordToBeChecked.charAt(i);

            // This mean all the letter should be small
            if( !isFirstLetterBig ) {
                if( Character.isUpperCase(testChar) ) {
                    retValue = false;
                    break;
                }
            }
            else {
                if( i == 1 && !Character.isUpperCase(testChar)) {
                    allSmallIsRequired = true;
                    continue;
                }

                boolean t = !Character.isUpperCase(testChar);
                if( t != allSmallIsRequired ) {
                    retValue = false;
                    break;
                }
            }
        }

        return retValue;
    }

    public boolean detectCapitalUse(String word) {
        // Sanity checking
        if( word == null ) return false;

        // A single length string would always be fine
        int wordLength = word.length();
        if( wordLength == 1 ) return true;

        // Setting up for the main function call
        char firstChar = word.charAt(0);
        boolean isUpper = Character.isUpperCase(firstChar);
        wordToBeChecked = word;

        // The method which would do the actual check
        return performCheck(isUpper);
    }
}
