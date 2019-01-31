# Problem URL: https://leetcode.com/problems/intersection-of-two-arrays/#/description

class Solution(object):
    def unique_numbers(self, numbers):
        un_numbers = []

        for number in numbers:
            if number not in un_numbers:
                un_numbers.append(number)
        
        return un_numbers

    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """

        numbers = self.unique_numbers(nums1)
        return_list = []

        for num in numbers:
            if num in nums2:
                return_list.append(num)
        
        return return_list

s = Solution()
print(s.intersection([1, 2, 2, 1], [2, 2]))    # Should return [2]