# Problem url: https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description

class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """

        # First should print out all the substrings

s = Solution()

print(s.findAnagrams('cbaebabacd','abc'))    # Should output [0, 6]
print(s.findAnagrams('abab','ab'))           # Should output [0, 1, 2]
