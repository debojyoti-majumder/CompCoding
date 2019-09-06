// https://leetcode.com/problems/corporate-flight-bookings/
// Problem Id: 1109

package com.leetcode;

import static org.junit.Assert.assertArrayEquals;
import org.junit.Test;

public class CorpFlightBookingsTest {
    @Test
    public void basicTest() {
        int[][] inp = new int[][]{{1,2,10},{2,3,20},{2,5,25}};
        CorpFlightBookings bookings = new CorpFlightBookings(inp, 5);
        assertArrayEquals(new int[] {10,55,45,25,25}, bookings.getSeatCount());
    }
}