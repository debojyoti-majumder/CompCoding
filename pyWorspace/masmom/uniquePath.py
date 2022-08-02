# Problem URL : https://leetcode.com/problems/unique-paths/
# This should again get a TLE Error
# TBD : Adding a DP table where if we find the destination node we are done

from typing import List


class Pathfinder:
    def __init__(self,m:int, n:int) -> None:
        self.numberOfRows = m
        self.numberOfCols = n
        self.destCount = 0

    """
    This is the value from the DP table that needs to be retunred
    """
    def getLastCellOutput(self) -> int:
        return self.destCount

    """
    The robot can only move in right and bottom making it not
    able to create loops
    """
    def getNextItems(self, x:int, y:int ) -> List[tuple[int,int]]:
        retItems = []
        lastRowIndex = self.numberOfRows - 1
        lastColIndex = self.numberOfCols - 1

        # This means we have reached our destination should update the value 
        # in this
        if x == lastRowIndex and y == lastColIndex:
            self.destCount += 1
            return []

        if x < lastRowIndex: retItems.append((x + 1, y))
        if y < lastColIndex: retItems.append((x, y + 1))

        return retItems
        

class Solution:
    def uniquePaths(self, m:int, n:int) -> int:
        if m == 0 or n == 0: return 0
        visitQueue:List[tuple[int,int]] = []
        pathFinder = Pathfinder(m,n)
        
        # Trying to go though the paths that leads to the destination
        visitQueue.append((0,0))
        while len(visitQueue) != 0:
            currItem = visitQueue.pop(0)
            nextItems = pathFinder.getNextItems(currItem[0], currItem[1])
            for item in nextItems : visitQueue.append(item)
            
        return pathFinder.getLastCellOutput()

sol = Solution()

print(sol.uniquePaths(4,2))
print(sol.uniquePaths(20,7))
