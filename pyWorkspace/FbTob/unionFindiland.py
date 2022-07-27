"""
Problem URL: https://leetcode.com/problems/number-of-islands/
Status : Needs debugging
"""

from typing import List, Set

class Cell:
    def __init__(self, x : int , y : int) -> None:
        self.x = x
        self.y = y
        self.Id = 0

    """
    If id is zero that means it is water
    """    
    def isIsland(self) -> bool:
        return self.Id != 0

    def getAdacentCells(self, xBound : int, yBound : int) -> List:
        adjcItems : List[Cell] = []

        # For left and right items
        if self.x != 0:
            adjcItems.append(Cell(self.x - 1, self.y))
        if self.x < xBound - 1: 
            adjcItems.append(Cell(self.x + 1, self.y))
        
        # For top and bottom
        if self.y != 0:
            adjcItems.append(Cell(self.x,self.y - 1))
        if self.y < yBound - 1:
            adjcItems.append(Cell(self.x, self.y + 1))
        
        return adjcItems

class Solution:
    def __init__(self) -> None:
        self.numberOfRows : int = 0
        self.numberOfCols : int = 0
        self.cellsList : List[List[Cell]]

    """
    Marks the cells which ones are water and which ones are 
    island. If Id is zero then it is water
    """
    def _initCells(self, grid: List[List[str]]) -> None:
        counter = 0
        self.cellsList = []

        for i in range(0, self.numberOfRows):
            rowCells : List[Cell] = []

            for j in range(0, self.numberOfCols):
                newCell = Cell(i,j)
                
                # Intially we are treating all the cells as individual area
                if grid[i][j] == "1":
                    counter += 1
                    newCell.Id = counter

                rowCells.append(newCell)
            
            self.cellsList.append(rowCells)

    def _getUniqueCells(self) -> Set[int]:
        uniqueCells : Set[int] = set([])
        
        for i in range(0, self.numberOfRows):
            for j in range(0, self.numberOfCols):
                cellId = self.cellsList[i][j].Id
                if cellId != 0: uniqueCells.add(cellId)

        return uniqueCells

    def numIslands(self, grid: List[List[str]]) -> int:
        self.numberOfRows = len(grid)
        if self.numberOfRows == 0 : return 0
        self.numberOfCols = len(grid[0])

        # This would create out main working matrix
        self._initCells(grid)
        
        # Now we have object type numbers for each cells
        for i in range(0,self.numberOfRows):
            for j in range(0, self.numberOfCols):
                currCell = self.cellsList[i][j]
                
                # No need to process 
                if currCell.isIsland() == False:
                    continue

                # Getting all the adjacent cells which are islands
                validCells : List[Cell] = []
                adjItems : List[Cell] = currCell.getAdacentCells(self.numberOfRows, self.numberOfCols)

                for item in adjItems:
                    adjNode = self.cellsList[item.x][item.y]
                    if adjNode.isIsland(): validCells.append(adjNode)

                # Calculating the minimum value
                minval = currCell.Id
                for cl in validCells:
                    if cl.Id < minval: minval = cl.Id
                
                for cl in validCells:
                    self.cellsList[cl.x][cl.y].Id = minval

        # We need to return count of regions that are created
        cellSet = self._getUniqueCells()
        return len(cellSet)


s1 = Solution()
grid1 = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
retValue = s1.numIslands(grid1)
print("Input 1:{0}".format(retValue))

grid2 = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

retValue = s1.numIslands(grid2)
print("Input 2:{0}".format(retValue))

# Should output 1
grid3 = [["1","0","1","1","1"],["1","0","1","0","1"],["1","1","1","0","1"]]
retValue = s1.numIslands(grid3)
print("Input 3:{0}".format(retValue))
