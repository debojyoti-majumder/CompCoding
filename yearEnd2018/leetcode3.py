# Problem url: https://leetcode.com/problems/count-primes/#/description

class Solution(object):
    def __get_nextNumber(self, number_list, start_number):
        # Should return the value
        for i in range(start_number, len(number_list)):
            if not number_list[i]:
                return i
        
        # Return -1 to say no more items found
        return -1

    def __get_false_count(self, number_list):
        return len(number_list) - sum(number_list)
    
    def countPrimes(self, n):
        visited_number_list = []
        
        if n == 0 or n == 1 or n==2:
            return 0
        
        # Creating the number list
        for i in range(n):
            visited_number_list.append(False)

        visited_number_list[0] = True
        visited_number_list[1] = True

        # Intilizing variables
        list_index = 0
        no_new_number_found = False
        start_number = 2

        while not no_new_number_found:
            item = self.__get_nextNumber(visited_number_list,start_number)
            multuiplier = 2
            no_new_number_found = True

            # This just avoid the inner loop
            if item == -1:
                item = n

            val = item * multuiplier
        
            while val < n:
                if not visited_number_list[val]:
                    visited_number_list[val] = True
                    no_new_number_found = False

                multuiplier = multuiplier + 1
                val = item * multuiplier
            
            start_number = item + 1

        return self.__get_false_count(visited_number_list)

s = Solution()
print(s.countPrimes(10))
print(s.countPrimes(499979))        # This time limit went away
print(s.countPrimes(999983))        # This one is getting stuck
