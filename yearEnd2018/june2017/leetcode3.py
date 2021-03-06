# Problem url: https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description

class Solution(object):
    def get_counter_map(self, input_string):
        counter_map = {}

        for letter in input_string:
            if letter in counter_map:
                counter_map[letter] += 1
            else:
                counter_map[letter] = 1

        return counter_map

    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """

        found_indexes = []
        find_string_map = self.get_counter_map(p)
        temp_string = s[:len(p) -1]
        source_string_map = self.get_counter_map(temp_string)

        for i in range(len(temp_string), len(s)):
            # New letter to be added in the sliding window
            new_letter = s[i]

            if new_letter in source_string_map:
                source_string_map[new_letter] += 1
            else:
                source_string_map[new_letter] = 1
            
            if source_string_map == find_string_map:
                found_indexes.append(i - len(temp_string))

            # Letter to be removed from the window
            char_to_remove = s[i - len(temp_string)]
            source_string_map[char_to_remove] -= 1

            # This is keep the map in a consistent state
            if source_string_map[char_to_remove] == 0 :
                del(source_string_map[char_to_remove])

        return found_indexes

s = Solution()

print(s.findAnagrams('cbaebabacd','abc'))       # Should output [0, 6]
print(s.findAnagrams('abab','ab'))              # Should output [0, 1, 2]
print(s.findAnagrams('ab','ab'))                # Should output [0]