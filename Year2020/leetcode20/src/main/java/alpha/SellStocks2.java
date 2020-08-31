// Problem URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Problem ID: 122 - Easy
// Status: Accepted

package alpha;

public class SellStocks2 {

    public int maxProfit(int[] prices) {
        int currentProfit = 0;
        boolean isStockBought = false;
        int holdValue = 0;

        // Base cases
        if( prices.length == 1 ) return 0;

        for( int i=1; i<prices.length; i++ ) {
            if( prices[i] > prices[i-1] && !isStockBought) {
                isStockBought = true;
                holdValue = prices[i-1];
            }
            // If this condition is false means that we are holding the stock
            else if(isStockBought && prices[i] < prices[i-1]) {
                currentProfit += prices[i-1] - holdValue;

                isStockBought = false;
                holdValue = 0;
            }
        }

        // At last if I have bough something that should be sold
        if(isStockBought) currentProfit += prices[prices.length-1] - holdValue;

        // Done
        return currentProfit;
    }
}
