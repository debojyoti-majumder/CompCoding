// https://leetcode.com/problems/brick-wall/
// Problem ID: 554

package com.leetcode;

import java.util.List;

public class BrickWallLineDraw {
    List<List<Integer>> _wallConfiguration;
    int _wallWidth;

    public BrickWallLineDraw(List<List<Integer>> wall) {
        _wallWidth = 0;
        _wallConfiguration = wall;
        List<Integer> firstRow = _wallConfiguration.get(0);

        // Each row should be summed up to the same value so we won't have to
        // get the max value
        for( int i=0; i<firstRow.size(); i++ )
            _wallWidth += firstRow.get(i);
    } 
    
    private boolean isMatched(int rowNumber, int lineOffset) {
        List<Integer> row = _wallConfiguration.get(rowNumber);
        int sum = 0;

        for( int i=0; sum<=lineOffset; i++ ) {
            // This is just for safekeeping
            if( i == row.size() ) break;
            else if( sum == lineOffset ) break;

            // Accumulating
            sum += row.get(i);
        }

        return sum == lineOffset ? true : false;
    }

    private int getCrossingScore(int lineOffset) {
        int retValue = 0;

        for( int i=0; i<_wallConfiguration.size(); i++ ) {
            // This means we have to cross the brick
            if( false == isMatched(i, lineOffset) ) retValue += 1; 
        }

        return retValue;
    }

    public int getMinCount() {

        if( _wallWidth <= 1 ) return _wallWidth;
        int retValue = 0;

        for( int i=1; i<_wallWidth; i++ ) {
            int tmp = getCrossingScore(i);

            // This is to update the mininum
            if( retValue != 0 ) {
                retValue = retValue > tmp ? tmp : retValue;
            }
            else {
                retValue = tmp;
            }
        } 

        return retValue;
    }
}