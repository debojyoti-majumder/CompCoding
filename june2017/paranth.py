# Problem Url: https://leetcode.com/problems/generate-parentheses/#/description

class Solution(object):
    def recurse_helper_function(self, num):
        patterns = []

        if num == 1:
            return ['()']

        ret_pattrns = self.recurse_helper_function(num-1)
        
        for pat in ret_pattrns:
            item = '()' + pat
            patterns.append(item)

            item = pat + '()'
            patterns.append(item)

            item = '(' + pat + ')'
            patterns.append(item)

        return patterns
        
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        # Getting all the patterns
        only_n_patterns = []
        all_patterns = self.recurse_helper_function(n)
        unique_items = []

        # Only n letter patterns are getting added
        for p in all_patterns:
            if len(p) == 2 * n:
                only_n_patterns.append(p)

        # Removing the duplicate once
        for p in only_n_patterns:
            if p not in unique_items:
                unique_items.append(p)

        return unique_items

s = Solution()

# Should generate all parenthesis with 2 pairs
# Ouput should be ()() (())
print(s.generateParenthesis(2))

# Should generate all parenthesis with 3 pairs
# Ouput should be ((())) ()(()) (())() ()()()
print(s.generateParenthesis(3))
