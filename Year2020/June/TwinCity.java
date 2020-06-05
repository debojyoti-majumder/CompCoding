// Problem URL: https://leetcode.com/problems/two-city-scheduling/
// Problem ID: 1029
package com.debojyoti;

import org.junit.Test;

import java.util.ArrayList;

public class TwinCity {
    private boolean isLess(int a, int b) {
        if( a < b ) return true;
        else return false;
    }

    public int twoCitySchedCostNeive(int[][] costs) {
        // Calculating number of empty slots
        int numberOfPersons = costs.length;
        int posLeftInA = numberOfPersons / 2;
        int posLeftInB = posLeftInA;
        int totalCost = 0;

        for(int personIndex = 0; personIndex < costs.length; personIndex++ ) {
            boolean isACostsLess = isLess(costs[personIndex][0], costs[personIndex][1]);

            if( isACostsLess ) {
                // That means there are room available
                if( posLeftInA != 0 ) {
                    posLeftInA--;
                    totalCost += costs[personIndex][0];
                }
                else {
                    posLeftInB--;
                    totalCost += costs[personIndex][1];
                }
            }
            else {
                if( posLeftInB != 0 ) {
                    posLeftInB--;
                    totalCost += costs[personIndex][1];
                }
                else {
                    posLeftInA--;
                    totalCost += costs[personIndex][0];
                }
            }
        }

        return totalCost;
    }

    private class CityCost {
        private int costOfA;
        private int costOfB;

        public CityCost(int a,int b) {
            this.costOfA = a;
            this.costOfB = b;
        }

        public int getCostOfA() {
            return this.costOfA;
        }

        public int getCostOfB() {
            return this.costOfB;
        }
    }

    private int getMinVal(ArrayList<CityCost> costs, boolean isA) {
        int minValue = Integer.MAX_VALUE;

        for( CityCost c : costs ) {
            int val = isA ? c.getCostOfA() : c.getCostOfB();
            if( val < minValue ) minValue = val;
        }

        return minValue;
    }

    private int recusriveSolver(ArrayList<CityCost> cost, int leftInA, int leftInB) {
        // These are my base cases
        if (leftInA == 1) return getMinVal(cost, true);
        if (leftInB == 1) return getMinVal(cost, false);

        CityCost currentCost = cost.get(0);
        cost.remove(currentCost);
        int cost1 = Integer.MAX_VALUE;
        int cost2 = Integer.MAX_VALUE;

        // These are the recursive solvers
        if (leftInA > 1) cost1 = currentCost.getCostOfA() + recusriveSolver(cost, leftInA - 1, leftInB);
        if (leftInB > 1) cost2 = currentCost.getCostOfB() + recusriveSolver(cost, leftInA, leftInB - 1);

        if( cost1 < cost2 ) return cost1;
        else return cost2;
    }

    public int twoCitySchedCost(int[][] costs) {
        int totalNumberOfPeople = costs.length;
        int slotsLeft = totalNumberOfPeople / 2;

        ArrayList<CityCost> cityCosts = new ArrayList<>();

        for( int i=0; i<totalNumberOfPeople; i++ ) {
            cityCosts.add(new CityCost(costs[i][0], costs[i][1]));
        }

        return recusriveSolver(cityCosts, slotsLeft, slotsLeft);
    }

    @Test
    public void testSolution() {
        // Sample input
        int[][] input = new int[][]{
                new int[] {10, 20},
                new int[] {30, 200},
                new int[] {400, 50},
                new int[] {30, 20}
        };

        int retValue = twoCitySchedCost(input);
        System.out.println("Return value: " + retValue);
        System.out.println("Bad algo output: " + twoCitySchedCostNeive(input));
        assert(retValue == 110);

        // Second test case
        int[][] input2 = new int[][]
        {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
        retValue = twoCitySchedCost(input2);
        System.out.println("Return value: " + retValue);
        System.out.println("Bad algo output: " + twoCitySchedCostNeive(input2));
        assert(retValue == 1859);
    }
}
