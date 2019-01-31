# https://leetcode.com/submissions/detail/160633114/

class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        
        profits = []
        
        for i in range(0, len(prices)):
            for j in range(i+1,len(prices)):
                p = prices[j] - prices[i]
                
                if p < 0 :
                    p = 0
                
                profits.append(p)
        
        if len(profits) == 0:
            return 0
        
        return max(profits)
