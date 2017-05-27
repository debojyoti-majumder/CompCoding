# Problem URL https://leetcode.com/problems/number-complement/#/description

class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        bit_checker = pow(2,31)
        given_number = num 
        count = 0

        for i in range(32):
            temp = given_number & bit_checker

            if temp == bit_checker:
                break

            given_number = given_number << 1
            count = count + 1

        bit_count =  32 - count
        all_one_number = pow(2, bit_count) - 1

        return all_one_number - num

s = Solution()

print(s.findComplement(5))     # Should return 2
print(s.findComplement(1))     # Should return 1
