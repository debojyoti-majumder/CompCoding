# Problem URL: https://leetcode.com/problems/majority-element/#/description
# Used algorithm: https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # Assuming the first item to be the majority item
        majority_count = 1
        item_index = 0

        for i in range(1,len(nums)):
            num = nums[i]

            if num == nums[item_index]:
                majority_count = majority_count + 1
            else:
                majority_count = majority_count - 1

            if majority_count == 0:
                majority_count = 1
                item_index = i
        
        return nums[item_index]

s = Solution()

print(s.majorityElement([2,2,2,2,5]))               # Should output 2 Occured floor(n/2)
print(s.majorityElement([1,1,1,1,3,3]))             # Should output 1
print(s.majorityElement([2,2,2,5,5,2,2]))           # Should output 2
