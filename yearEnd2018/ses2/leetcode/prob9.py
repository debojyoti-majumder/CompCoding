class Solution(object):
    def superPow(self, a, b):
        if not b:
            return 1
        return pow(a, b.pop(), 1337)*self.superPow(pow(a, 10, 1337), b)%1337
