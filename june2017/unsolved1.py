# If a number c can be writen in a^2 + b^2 = c^2 or not, not yet solved
# Problem link: https://leetcode.com/contest/leetcode-weekly-contest-39/problems/sum-of-square-numbers/

import math

class Solution(object):
    def primes(self,n):
        primfac = []
        d = 2
        
        while d*d <= n:
            while (n % d) == 0:
                primfac.append(d)  # supposing you want multiple factors repeated
                n //= d
            
            d += 1
            
        if n > 1:
            primfac.append(n)
        
        return primfac

    def judgeSquareSum(self, c):
        pms = self.primes(c)

        factor_map = {}

        for p in pms:
            if p not in factor_map:
                factor_map[p] = 1
            else:
                factor_map[p] = factor_map[p] + 1
        
        l = len(factor_map)

        if l == 1:
            item = factor_map.keys()[0]
            
            if factor_map[item] % 2 == 0:
                return True
                
            # Perform 4k + 1
            m = (item - 1) / 4
            if item == 4*m + 1:
                return True
            else:
                return False

        if l == 2:
            if factor_map[factor_map.keys()[0]] == factor_map[factor_map.keys()[1]] and factor_map[factor_map.keys()[0]] % 2 == 0:
                return True
            else:
                return False

s = Solution()

print(s.judgeSquareSum(3))          # Should return false
print(s.judgeSquareSum(4))          # Should return false
print(s.judgeSquareSum(5))          # Should return true
print(s.judgeSquareSum(6))          # Should return true
print(s.judgeSquareSum(13))         
print(s.judgeSquareSum(10000000))   #Memory Limit
