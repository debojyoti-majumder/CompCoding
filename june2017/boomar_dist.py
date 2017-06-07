# Problem URL:https://leetcode.com/problems/number-of-boomerangs/#/description

class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        boomerang_counter = 0

        return boomerang_counter
        
s = Solution()

#Explanation:
#The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
print(s.numberOfBoomerangs([[0,0],[1,0],[2,0]])) # Should output 2