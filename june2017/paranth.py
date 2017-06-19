# Problem Url: https://leetcode.com/problems/generate-parentheses/#/description

class Solution(object):
    pattern_list = []

    def recurse_helper_function(self, number_of_left, number_of_right, pattern):
        if number_of_left == number_of_right and number_of_left == 0:
            str_value = ''.join(pattern)
            self.pattern_list.append(str_value)
        
        if number_of_left > 0:
            pattern.append('(')
            self.recurse_helper_function(number_of_left-1, number_of_right, pattern)
            del pattern[-1]
        
        if number_of_right > number_of_left:
            pattern.append(')')
            self.recurse_helper_function(number_of_left, number_of_right-1, pattern)
            del pattern[-1]

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        
        # Intializing the paramter values
        self.pattern_list[:] = []

        # Calling the recusive function
        self.recurse_helper_function(n,n,[])
        
        # Returning the values
        return self.pattern_list

s = Solution()

# Should generate all parenthesis with 2 pairs
# Ouput should be ()() (())
print(s.generateParenthesis(2))

# Should generate all parenthesis with 3 pairs
# Ouput should be ((())) ()(()) (())() ()()()
print(s.generateParenthesis(3))
