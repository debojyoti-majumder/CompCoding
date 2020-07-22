// Problem URL: https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/
// Problem ID: 442

package com.debojyoti;

import org.hamcrest.CoreMatchers;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertThat;

public class FindDuplicate {
    private List<Integer> returnValue;

    public void merge(int[] leftPart, int[] rightPart, int[] output) {
        int leftIndex = 0, rightIndex = 0, outputIndex = 0;
        int leftSize = leftPart.length;
        int rightSize = rightPart.length;

        while( leftIndex < leftSize && rightIndex < rightSize ) {
            // Adding to main result
            if( leftPart[leftIndex] == rightPart[rightIndex] ) returnValue.add(leftPart[leftIndex]);

            if( leftPart[leftIndex] < rightPart[rightIndex] ) output[outputIndex++] = leftPart[leftIndex++];
            else output[outputIndex++] = rightPart[rightIndex++];
        }

        // Copying the rest of the left part
        while( leftIndex < leftSize ) output[outputIndex++] = leftPart[leftIndex++];

        // Doing the same for the right part
        while( rightIndex < rightSize ) output[outputIndex++] = rightPart[rightIndex++];
    }

    public void recusrsiveSort(int[] number) {
        // This is the base case
        int size = number.length;
        if( size < 2 ) return;

        int midIndex = size / 2;
        int leftPartSize = midIndex;
        int[] leftArray = new int[leftPartSize];

        int rightPartSize = size - midIndex;
        int[] rightArray = new int[rightPartSize];
        int rightIndex = 0;

        for( int index=0; index<size; index++ ) {
            if( index < midIndex ) leftArray[index] = number[index];
            else rightArray[rightIndex++] = number[index];
        }

        recusrsiveSort(leftArray);
        recusrsiveSort(rightArray);

        // Calling the merge
        merge(leftArray, rightArray, number);
    }

    public List<Integer> mainMethod(int[] input) {
        returnValue = new ArrayList<>();
        recusrsiveSort(input);
        return returnValue;
    }

    @Test
    public void testMethod() {
        FindDuplicate dup = new FindDuplicate();
        int[] numbers = new int[] {4,3,2,7,8,2,3,1};
        List<Integer> ret = dup.mainMethod(numbers);
        assertThat(ret, CoreMatchers.hasItems(2,3));

        int[] input1 = new int[] { 2,3 };
        List<Integer> output1 = dup.mainMethod(input1);
        assertThat(output1.size(), CoreMatchers.equalTo(0));

        int[] input2 = new int[] {10,10};
        List<Integer> output2 = dup.mainMethod(input2);
        assertThat(output2, CoreMatchers.hasItems(10));
    }
}
