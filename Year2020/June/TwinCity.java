// Problem URL: https://leetcode.com/problems/two-city-scheduling/
// Problem ID: 1029

package com.debojyoti;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Collections;

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

    private class CityCost implements Comparable<CityCost> {
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

        @Override
        public int compareTo(CityCost o) {
            Integer costLhs = Math.abs(this.costOfA - this.costOfB);
            Integer costRhs = Math.abs(o.getCostOfA() - o.getCostOfB());
            return costLhs.compareTo(costRhs);
        }
    }

    private CityCost getMinVal(ArrayList<CityCost> costs, boolean isA) {
        int minValue = Integer.MAX_VALUE;
        CityCost retObject = null;

        for( CityCost c : costs ) {
            int val = isA ? c.getCostOfA() : c.getCostOfB();

            if( val < minValue ) {
                minValue = val;
                retObject = c;
            };
        }

        return retObject;
    }

    private int recursiveSolver(ArrayList<CityCost> cost, int leftInA, int leftInB) {
        if( cost.isEmpty() ) return 0;

        // These are my base cases
        if (leftInA == 1) {
            CityCost minCosted = getMinVal(cost, true);
            cost.remove(minCosted);
            return minCosted.getCostOfA() + recursiveSolver(cost, 0, leftInB);
        };

        if (leftInB == 1) {
            CityCost minCosted = getMinVal(cost, false);
            cost.remove(minCosted);
            return minCosted.getCostOfB() + recursiveSolver(cost, leftInA, 0);
        }

        CityCost currentCost = cost.get(0);
        cost.remove(currentCost);
        int cost1 = Integer.MAX_VALUE;
        int cost2 = Integer.MAX_VALUE;

        // These are the recursive solvers
        if (leftInA > 1) {
            cost1 = currentCost.getCostOfA() + recursiveSolver((ArrayList<CityCost>) cost.clone(),
                    leftInA - 1, leftInB);
        }

        if (leftInB > 1) {
            cost2 = currentCost.getCostOfB() + recursiveSolver((ArrayList<CityCost>) cost.clone(),
                    leftInA, leftInB - 1);
        }

        if( cost1 < cost2 ) return cost1;
        else return cost2;
    }

    public int twoCitySchedCostRec(int[][] costs) {
        int totalNumberOfPeople = costs.length;
        int slotsLeft = totalNumberOfPeople / 2;

        ArrayList<CityCost> cityCosts = new ArrayList<>();

        for( int i=0; i<totalNumberOfPeople; i++ ) {
            cityCosts.add(new CityCost(costs[i][0], costs[i][1]));
        }

        return recursiveSolver(cityCosts, slotsLeft, slotsLeft);
    }

    private int performSortedAllocation(ArrayList<CityCost> costs) {
        int numberOfPeople = costs.size();
        int slotsLeftInA = numberOfPeople / 2;
        int slotsLeftInB = slotsLeftInA;
        int totalCost = 0;

        // Sorting based on difference in cost value
        Collections.sort(costs, Collections.reverseOrder());

        for(int index=0; index<numberOfPeople; index ++ ) {
            CityCost currentItem = costs.get(index);
            int aCost = currentItem.getCostOfA();
            int bCost = currentItem.getCostOfB();

            if( aCost < bCost ) {
                if( slotsLeftInA > 0 ) {
                    totalCost += aCost;
                    slotsLeftInA--;
                }
                else {
                    totalCost += bCost;
                    slotsLeftInB--;
                }
            }
            else {
                if( slotsLeftInB > 0 ) {
                    totalCost += bCost;
                    slotsLeftInB--;
                }
                else {
                    totalCost += aCost;
                    slotsLeftInA--;
                }
            }
        }

        return totalCost;
    }

    public int twoCitySchedCost(int[][] costs) {
        int totalNumberOfPeople = costs.length;
        int slotsLeft = totalNumberOfPeople / 2;

        ArrayList<CityCost> cityCosts = new ArrayList<>();

        for( int i=0; i<totalNumberOfPeople; i++ ) {
            cityCosts.add(new CityCost(costs[i][0], costs[i][1]));
        }

        return performSortedAllocation(cityCosts);
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
        System.out.println("Recusor algo output: " + twoCitySchedCostRec(input));
        assert(retValue == 110);

        // Second test case
        int[][] input2 = new int[][]
        {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
        retValue = twoCitySchedCost(input2);
        System.out.println("Return value: " + retValue);
        System.out.println("Bad algo output: " + twoCitySchedCostNeive(input2));
        System.out.println("Recusor algo output: " + twoCitySchedCostRec(input));
        assert(retValue == 1859);
    }

    @Test
    public void extendedTest() {
       int[][] input = {
               {918,704},{77,778},{239,457},{284,263},{872,779},{976,416},{860,518},{13,351},
            {137,238},{557,596},{890,227},{548,143},{384,585},{165,54}};
       System.out.println("Re cursor algo output: " + twoCitySchedCostRec(input));
       assert(twoCitySchedCost(input) == 4532);
    }
}
