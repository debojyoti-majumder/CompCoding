# Problem URL:https://leetcode.com/problems/number-of-boomerangs/#/description

class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        boomerang_counter = 0

        permute_iterator = self.all_perms(points)
        
        while True:
            try:
                target_item = permute_iterator.next()
                print(target_item)
            except StopIteration:
                break
            
        return boomerang_counter

    def all_perms(self,elements):
        if len(elements) <=1:
            yield elements
        else:
            for perm in self.all_perms(elements[1:]):
                for i in range(len(elements)):
                    # nb elements[0:1] works in both string and list contexts
                    yield perm[:i] + elements[0:1] + perm[i:]

s = Solution()

#Explanation:
#The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
print(s.numberOfBoomerangs([[0,0],[1,0],[2,0]])) # Should output 2