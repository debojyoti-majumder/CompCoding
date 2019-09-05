package com.leetcode;

import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class FruitBasketCollectorTest {
    @Test
    public void basicTests() {
        FruitBasketCollector cl1 = new FruitBasketCollector(new int[] {1,2,1});
        assertEquals(3, cl1.getMaxScore());

        // Explanation: We can collect [1,2,2], If we started at the first tree, we would only collect [0, 1].
        FruitBasketCollector cl2 = new FruitBasketCollector(new int[]{0,1,2,2});
        assertEquals(3, cl2.getMaxScore());

        // If we started at the first tree, we would only collect [1, 2].
        FruitBasketCollector cl3 = new FruitBasketCollector(new int[]{1,2,3,2,2});
        assertEquals(4, cl3.getMaxScore());
    }
}