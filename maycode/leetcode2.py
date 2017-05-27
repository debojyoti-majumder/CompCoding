# Problem URL: https://leetcode.com/problems/ransom-note/#/description
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        

s = Solution()

s.canConstruct("a", "b")        #Should return false
s.canConstruct("aa", "ab")      #Should return false
s.canConstruct("aa", "aab")     #Should return true
