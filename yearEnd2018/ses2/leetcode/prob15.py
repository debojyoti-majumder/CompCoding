# https://leetcode.com/problems/my-calendar-i/description/

class MyCalendar:

    def __init__(self):
        self.bookingVector = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        retVal = True
        toBeReverted = []

        if end > len(self.bookingVector) :
            for i in range(0,end - len(self.bookingVector)):
                self.bookingVector.append(0)
        
        for index in range(start, end) :
            if self.bookingVector[index] == 0 or start == index:
                if self.bookingVector[index] == 0 :
                    toBeReverted.append(index)
                    
                self.bookingVector[index] = 1
            else :
                retVal = False
                break
        
        # If not booked then revert the half transaction
        if retVal == False:
            for r in toBeReverted:
                self.bookingVector[r] = 0

        return retVal
