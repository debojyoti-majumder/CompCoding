#Problem URL: https://leetcode.com/problems/intersection-of-two-arrays-ii/#/description

class Solution(object):
    def get_number_map(self, numbers):
        number_map = {}

        for num in numbers:
            if num in number_map:
                number_map[num] += 1
            else:
                number_map[num] = 1

        return number_map

    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        return_list = []

        num_map_1 = self.get_number_map(nums1)
        num_map_2 = self.get_number_map(nums2)

        for item in num_map_1:
            if item in num_map_2:
                for i in range(min(num_map_1[item],num_map_2[item])):
                    return_list.append(item)

        return return_list

s = Solution()
print(s.intersect([1,2,2,1],[2,2]))                     # Should output [2,2]
print(s.intersect([1,2,3,44,4,5,5,6,6,1,1,1,2],[1,6]))  # Should output [1,6]   