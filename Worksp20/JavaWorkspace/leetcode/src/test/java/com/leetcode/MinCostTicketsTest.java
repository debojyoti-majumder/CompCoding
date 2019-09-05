package com.leetcode;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class MinCostTicketsTest {
    @Test
    public void basicTest() {
        // Explanation: 
        // For example, here is one way to buy passes that lets you travel your travel plan:
        // On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
        // On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
        // In total you spent $17 and covered all the days of your travel.
        MinCostTickets tk = new MinCostTickets(2, 7, 15);
        int output = tk.getMinCostForTrip(new int[] {1,2,3,4,5,6,7,8,9,10,30,31});
        assertEquals(17, output);
    }
}