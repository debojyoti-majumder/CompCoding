# Problem URL: https://leetcode.com/problems/super-pow/description/

class Solution:
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """

        sum = 0
        powerLength = len(b)

        for i in range(0, powerLength):
            sum += pow(10, powerLength - i - 1) * b[i]

        retValue = 1
        for i in range(0,sum):
            retValue = retValue * a
            retValue = retValue % 1337

        return retValue

        
s = Solution()
print(s.superPow(2,[1,6]))
