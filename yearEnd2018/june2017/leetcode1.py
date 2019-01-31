# Problem url: https://leetcode.com/problems/student-attendance-record-i/#/description

class Solution(object):
    def __check_for_absent(self, s): 
        if s.count('A') > 1:
            return True
        else:
            return False

    def __check_for_late(self, s):
        lates_count = 0
        is_late = False

        for i in range(len(s)):
            if lates_count > 0 :
                if s[i] == 'L':
                    lates_count = lates_count + 1
                else:
                    lates_count = 0
            else:
                if s[i] == 'L':
                    lates_count = 1
            
            if lates_count > 2:
                is_late = True
                break

        return is_late

    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        is_late = self.__check_for_late(s)
        is_absent = self.__check_for_absent(s)
        
        return not (is_late or is_absent)

s = Solution()

print(s.checkRecord('PPALLP'))      # Should return true
print(s.checkRecord('PPALLL'))      # Should return false
print(s.checkRecord('LLLALL'))      # Now this passes
