// Problem URL: https://leetcode.com/problems/brick-wall/
// Problem ID:  554

//Input: [[1,2,2,1],
//        [3,1,2],
//        [1,3,2],
//        [2,4],
//        [3,1,2],
//        [1,3,1,1]]

//Output: 2

package com.leetcode;

import java.util.List;

import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.Arrays;

import org.junit.Test;

public class BrickWallLineDrawTest {
    @Test
    public void basicTest() {
        List<Integer> row1 = Arrays.asList(1,2,2,1);
        List<Integer> row2 = Arrays.asList(3,1,2);
        List<Integer> row3 = Arrays.asList(3,1,2);
        List<Integer> row4 = Arrays.asList(3,1,2);
        List<Integer> row5 = Arrays.asList(3,1,2);
        List<Integer> row6 = Arrays.asList(3,1,2);

        List<List<Integer>> numbers = new ArrayList<List<Integer>>();
        numbers.add(row1);
        numbers.add(row2);
        numbers.add(row3);
        numbers.add(row4);
        numbers.add(row5);
        numbers.add(row6);

        BrickWallLineDraw linedrawer = new BrickWallLineDraw(numbers);
        assertEquals(2, linedrawer.getMinCount());
    }
}