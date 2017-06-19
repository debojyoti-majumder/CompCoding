# Problem Url: https://leetcode.com/problems/valid-parentheses/#/description

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        symbol_stack = []

        for sym in s:
            if sym == '(' or sym == '{' or sym == '[':
                symbol_stack.append(sym)
                continue
            
            if len(symbol_stack) == 0:
                return False
            
            if sym == ')':
                top_symbol = symbol_stack.pop()
                if top_symbol != '(':
                    return False

            if sym == '}':
                top_symbol = symbol_stack.pop()
                if top_symbol != '{':
                    return False

            if sym == ']':
                top_symbol = symbol_stack.pop()
                if top_symbol != '[':
                    return False

        if len(symbol_stack) > 0:
            return False
        else:
            return True

s = Solution()    

print(s.isValid('['))
print(s.isValid('{{])'))
