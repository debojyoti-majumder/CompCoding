// Problem URL: https://leetcode.com/problems/fruit-into-baskets/
// Problem ID: 904

package com.leetcode;

public class FruitBasketCollector {
    class FruitBucket {
        public int fruitType;
        public int count;

        public FruitBucket() {
            // Indicates empty
            fruitType = -1;
            count = 0;
        }

        public boolean isEmpty() {
            return fruitType == -1;
        }
    }

    private FruitBucket _bucketOne;
    private FruitBucket _bucketTwo;
    private int[] _treeArray;

    public FruitBasketCollector(int[] trees) {
        _bucketOne = new FruitBucket();
        _bucketTwo = new FruitBucket();
        _treeArray = trees;
    }

    private boolean updateBucket(int type) {
        if( _bucketOne.isEmpty() ) {
            _bucketOne.count = 1;
            _bucketOne.fruitType = type;
            return true;
        }

        if( _bucketTwo.isEmpty() ) {
            _bucketTwo.count = 1;
            _bucketTwo.fruitType = type;
            return true;
        }

        if( _bucketOne.fruitType == type ) {
            _bucketOne.count++;
            return true;
        }

        if( _bucketTwo.fruitType == type ) {
            _bucketTwo.count++;
            return true;
        }

        return false;
    }

    public int getMaxScore(int startIndex) {
        int retVal = 0;
        int numberOfTrees = _treeArray.length;
        int i = 0;

        // This should be in order of n
        for( i=startIndex; i<numberOfTrees; i++ ) {
            if ( !updateBucket(_treeArray[i]) )
                break;
        }

        // Add to retrun value if it's not empty
        if( false == _bucketOne.isEmpty() ) retVal += _bucketOne.count;
        if( false == _bucketTwo.isEmpty() ) retVal += _bucketTwo.count;
        
        // That means we had to stop
        if( i != numberOfTrees ) {
            _bucketOne = new FruitBucket();
            _bucketTwo = new FruitBucket();

            // Get the max value
            int startOverValue = getMaxScore(i-1);
            retVal = Math.max(retVal, startOverValue);
        }

        return retVal;
    }
}