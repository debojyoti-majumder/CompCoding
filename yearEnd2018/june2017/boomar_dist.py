# Problem URL:https://leetcode.com/problems/number-of-boomerangs/#/description
import itertools

class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        boomerang_counter = 0
        
        combinations = list(itertools.combinations(points,3))
        for comb in combinations:
            permuted_items = list(itertools.permutations(comb))
            for item in permuted_items:
                if self.is_boomerang(item):
                    boomerang_counter += 1
            
        return boomerang_counter

    def get_distance(self, point1, point2):
        sq_val = (point1[0] - point2[0]) ** 2 
        sq_val += (point1[1] - point2[1]) ** 2

        # Return the square root
        return sq_val ** 0.5

    def is_boomerang(self, points) :
        point_1 = points[0]
        point_2 = points[1]
        point_3 = points[2]

        if self.get_distance(point_1,point_2) == self.get_distance(point_1,point_3):
            return True
        else:
            return False

s = Solution()

#Explanation:
#The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
print(s.numberOfBoomerangs([[0,0],[1,0],[2,0]]))                # Should output 2
print(s.numberOfBoomerangs([[0,0],[1,0],[-1,0],[0,1],[0,-1]]))  # Should output 20