// Problem URL: https://leetcode.com/problems/hand-of-straights/
// Sorting the array is not a option because of cases like this [1,2,3,6,2,3,4,7,8],3

package com.debojyoti;

import java.util.Arrays;

class StraightHandChecker {
    private int[] _numbers;
    private int _groups;
    private boolean _processed;

    StraightHandChecker(int[] numbers, int numberOfGroups) {
        // Number is stored as sorted
        _numbers = numbers;
        _groups = numberOfGroups;

        // This means that it can be put in equal groups
        if( _numbers.length % numberOfGroups != 0 )
            _processed = false;
        else {
            _processed = true;
            Arrays.sort(_numbers);
        }
    }

    private boolean isOkay(int[] num) {
        int val = num[0];

        for( int i=1; i<num.length; i++ ) {
            // The values should be sequential like 2,3,4 8,9,10
            val += 1;
            if( num[i] != val )
                return false;
        }

        return true;
    }

    boolean isStraight() {
        // This is kind of a optimization
        if( false == _processed )
            return false;

        // Kind of wost case scenario
        if( _numbers.length == _groups )
            return true;

        for( int i=0; i<_numbers.length; i += _groups ) {
            int[] tempArray = Arrays.copyOfRange(_numbers, i , i+_groups);
            if( false == isOkay(tempArray) )
                return false;
        }
        return true;
    }
}
