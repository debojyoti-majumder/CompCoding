# Problem URL: https://leetcode.com/problems/ransom-note/#/description

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """

        return_value = True
        magazine = list(magazine)

        for item in ransomNote:
            try:
                item_index = magazine.index(item)
                magazine.pop(item_index)

            except ValueError:
                return_value = False
                break

        return return_value
        

s = Solution()

print(s.canConstruct("a", "b"))        #Should return false
print(s.canConstruct("aa", "ab"))      #Should return false
print(s.canConstruct("aa", "aab"))     #Should return true
