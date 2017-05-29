# Problem url: https://leetcode.com/problems/count-primes/#/description

class Solution(object):
    def countPrimes(self, n):
        number_list = []
        
        if n == 0 or n == 1 or n==2:
            return 0
        
        # Creating the number list
        for i in range(2, n):
            number_list.append(i)

        # Intilizing variables
        list_index = 0
        no_new_number_found = False

        while not no_new_number_found:
            item = number_list[list_index]
            multuiplier = 2
            no_new_number_found = True

            val = item * multuiplier
        
            while val <= n:
                try:
                    item_index = number_list.index(val)
                    number_list.pop(item_index)
                    no_new_number_found = False

                except ValueError:
                    pass

                multuiplier = multuiplier + 1
                val = item * multuiplier

            # go to the next item in the list
            list_index = list_index + 1

        # 2 is not treated as prime
        return len(number_list)

s = Solution()
print(s.countPrimes(10))
print(s.countPrimes(499979))        # Got a time limit problem
