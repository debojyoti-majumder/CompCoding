// Problem URL: https://leetcode.com/problems/minimum-cost-for-tickets/description/
// ID: 983

package com.leetcode;

public class MinCostTickets {
    private int _onedayCost;
    private int _severdayCost;
    private int _fifteendaysCost;

    public MinCostTickets(int x, int y, int z) {
        _onedayCost = x;
        _severdayCost = y;
        _fifteendaysCost = z;
    }

    public int getMinCostForTrip(int[] costArray) {
        return _onedayCost + _severdayCost + _fifteendaysCost;
    }
}