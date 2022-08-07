# Problem URL : https://leetcode.com/problems/unique-paths/
# This should again get a TLE Error
# Sumission log: Accepted Used DP
# I tkink we can just use a map instead of a matrix because we would not
# be needing older values. The values of top row only
# Related problems: https://leetcode.com/problems/minimum-path-sum/

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
    def __init__(self) -> None:
        self.numberOfRows:int = 0
        self.numberOfCols:int = 0

        # Can we define a type for this
        self.dpTable = None

    """
    This method calculates the path by iterating it. The below method
    which uses DP would only work the the robot moves to right and down 
    only. If it make other moves it would create a loop
    """
    def iteratePath(self,m:int, n:int) -> int:
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

    """
    Uses values from cell top and from left
    """
    def uniquePaths(self, m:int, n:int) -> int:
        # Basic validity
        if m == 0 or n == 0: return 0
        
        # Will create a 2D array for the DP table
        self.numberOfRows = m
        self.numberOfCols = n
        self.dpTable = [ [0] * n for _ in range(m)]

        # If it is a 1/1 matrix then this value is 1
        self.dpTable[0][0] = 1

        # The runtime of the method is simply m*n
        for i in range(0,self.numberOfRows):
            for j in range(0,self.numberOfCols):
                calculatedSum = self.dpTable[i][j]

                # This is for the left cell
                if i > 0: calculatedSum += self.dpTable[i-1][j]
                # This is for the top cell
                if j > 0: calculatedSum += self.dpTable[i][j-1]

                self.dpTable[i][j] = calculatedSum

        # Last cell is our target location to reach
        lastCellx = self.numberOfRows - 1
        lastCelly = self.numberOfCols - 1
        return self.dpTable[lastCellx][lastCelly]

sol = Solution()

print(sol.uniquePaths(4,2))
print(sol.uniquePaths(20,7))
print(sol.uniquePaths(22,7))
