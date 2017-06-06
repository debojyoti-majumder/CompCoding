# Problem description: https://leetcode.com/problems/first-unique-character-in-a-string/#/description

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret_index = -1
        char_count_map = {}

        for i in range(len(s)):
            ch = s[i]
            
            if ch in char_count_map:
                char_count_map[ch] += 1
            else:
                char_count_map[ch] = 1
        
        indexes = []

        for item in char_count_map:
            if char_count_map[item] == 1:
                indexes.append(s.index(item))

        if len(indexes) > 0:
            ret_index = min(indexes)
        else:
            ret_index = -1

        return ret_index
    
s = Solution()

print(s.firstUniqChar('leetcode'))      # Should print 0 
print(s.firstUniqChar('loveleetcode'))  # Should print 2
