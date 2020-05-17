// Problem URL: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Problem ID: 1043

package com.debojyoti;

import org.hamcrest.CoreMatchers;
import org.junit.Test;
import static org.junit.Assert.assertThat;

public class PartitionArrayMaxSum {
    private int[] inputArray;
    private int K;

    private void buildTopN(int n) {
        int size = this.inputArray.length;
        // List<Integer> returnValue = new ArrayList<>();

        for( int i=0; i<size; i++ ) {
            int maxValue = this.inputArray[i];
            int maxIndex = i;

            // Look for the maximum value
            for( int j=i+1; j<size; j++ ) {
                if( this.inputArray[j] > maxValue ) {
                    maxValue = this.inputArray[j];
                    maxIndex = j;
                }
            }

            // Now make the swap
            int tmp = this.inputArray[i];
            this.inputArray[i] = maxValue;
            this.inputArray[maxIndex] = tmp;

            // Save the index
            // returnValue.add(maxIndex);
        }
    }

    private int getTopSum() {
        int itemsLeft = this.inputArray.length;
        int index = 0;
        int sum = 0;

        while( itemsLeft > 0 ) {
            if( itemsLeft < K ) {
                sum += this.inputArray[index] * itemsLeft;
                itemsLeft = 0;
            }
            else {
                sum += this.inputArray[index] * this.K;
                itemsLeft -= K;
            }

            index++;
        }

        return sum;
    }

    public int maxSumAfterPartitioning(int[] A, int K) {
        int len = A.length;

        // Initializing the members
        this.inputArray = A;
        this.K = K;

        int topNItemsNeeded = (int) Math.ceil(len / K );

        buildTopN(topNItemsNeeded);
        return getTopSum();
    }

    @Test
    public void basicTest() {
        int[] basicInput = new int[] {1,15,7,9,2,5,10};
        PartitionArrayMaxSum sum = new PartitionArrayMaxSum();

        int maxVal = sum.maxSumAfterPartitioning(basicInput, 3);
        assertThat(maxVal, CoreMatchers.equalTo(84));
    }

    @Test
    public void maxValueTest() {
        int[] input = new int[] {19,18,17,3,4,5,6,7};
        PartitionArrayMaxSum s = new PartitionArrayMaxSum();

        int val = s.maxSumAfterPartitioning(input, 3);
        assertThat(val, CoreMatchers.equalTo(110));
    }
}
