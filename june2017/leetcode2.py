# Problem description: https://leetcode.com/problems/first-unique-character-in-a-string/#/description

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret_index = -1

        for i in range(len(s)):
            if s.count(s[i]) == 1:
                ret_index = i
                break
        
        return ret_index
    
s = Solution()

print(s.firstUniqChar('leetcode'))      # Should print 0 
print(s.firstUniqChar('loveleetcode'))  # Should print 2
