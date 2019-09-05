// Problem URL: https://leetcode.com/problems/minimum-cost-for-tickets/description/
// ID: 983

package com.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Vector;

public class MinCostTickets {
    private int _onedayCost;
    private int _sevendayCost;
    private int _fifteendaysCost;

    public MinCostTickets(int x, int y, int z) {
        _onedayCost = x;
        _sevendayCost = y;
        _fifteendaysCost = z;
    }

    public int getMinCostForTrip(int[] costArray) {
        Vector<Integer> costs = new Vector<>();
        for( int i=0; i<costArray.length; i++ )
            costs.add(costArray[i]);

        return getMinCostForTrip(costs);
    }

    private int getMinCostForTrip(Vector<Integer> days) {
        int travelDays = days.size();
        int minVal = days.get(0);

        // Base case
        if( travelDays == 0 ) return 0;

        Vector<Integer> withOneDayTkt = new Vector<>();
        Vector<Integer> withSevenDayTkt = new Vector<>();
        Vector<Integer> withThirtyDayTkt = new Vector<>();

        for( int i=0; i<days.size(); i++ ) {
            int currentDay = days.get(i);
            
            if( currentDay > minVal ) withOneDayTkt.add(currentDay);
            if( currentDay - minVal > 7 ) withSevenDayTkt.add(currentDay);
            if( currentDay - minVal > 30 ) withThirtyDayTkt.add(currentDay);
        }
        
        // Returning the min costs
        ArrayList<Integer> costs = new ArrayList<>();
        costs.add(_onedayCost + getMinCostForTrip(withOneDayTkt));
        costs.add(_sevendayCost + getMinCostForTrip(withSevenDayTkt));
        costs.add(_fifteendaysCost + getMinCostForTrip(withThirtyDayTkt));
        return Collections.min(costs);
    }
}