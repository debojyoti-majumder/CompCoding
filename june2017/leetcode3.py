# Problem url: https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description

class Solution(object):

    def isAnargram(self, string_1, string_2):
        """
            returns true if the strings are anargram
        """
        char_list = list(string_2)

        for letter in string_1:
            try:
                char_index = char_list.index(letter)
                char_list.remove(letter)
            except ValueError:
                return False
                
        return True

    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        found_indexes = []

        # First should print out all the substrings
        for i in range(len(s)- len(p) + 1):
            sub_string = s[i:i+len(p)]

            # Sanity check
            if sub_string == None:
                break

            if self.isAnargram(sub_string,p):
                found_indexes.append(i)

        return found_indexes

s = Solution()

print(s.findAnagrams('cbaebabacd','abc'))       # Should output [0, 6]
print(s.findAnagrams('abab','ab'))              # Should output [0, 1, 2]
print(s.findAnagrams('ab','ab'))                # Should output [0]