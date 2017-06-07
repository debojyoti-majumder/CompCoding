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
                
                # Increment the counter if it is a boomereng
                if self.is_boomerang(target_item):
                   boomerang_counter += 1

            except StopIteration:
                break
            
        return boomerang_counter

    # Generates all the permutation
    def all_perms(self,elements):
        if len(elements) <=1:
            yield elements
        else:
            for perm in self.all_perms(elements[1:]):
                for i in range(len(elements)):
                    # nb elements[0:1] works in both string and list contexts
                    yield perm[:i] + elements[0:1] + perm[i:]

    def get_distance(self, point1, point2):
        sq_val = (point1[0] - point2[0]) ** 2 
        sq_val += (point1[1] - point2[1]) ** 2

        # Return the square root
        return sq_val ** 0.5

    def is_boomerang(self, points) :
        point_1 = points[0]
        point_2 = points[1]
        point_3 = points[2]

        if self.get_distance(point_1,point_2) == self.get_distance(point_2,point_3):
            return True
        else:
            return False

s = Solution()

#Explanation:
#The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
print(s.numberOfBoomerangs([[0,0],[1,0],[2,0]])) # Should output 2