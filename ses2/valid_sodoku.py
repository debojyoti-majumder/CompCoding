# Problem url: https://leetcode.com/problems/valid-sudoku/description/

class Solution(object):
    def getBoxFromBoard(self, board):
        num_box = []
        count = 0;

        # This should not happen but still kept it to safegaurd
        if len(board) < 9 :
            return num_box;

        for i in range(0,3):
            num_row = [];

            for k in range(0,3): 
                num_row.append(board[count])
                count = count + 1
            
            num_box.append(num_row);
            
        return num_box;

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(0,len(board)):
            row_cells = [i]
            col_cells = [i]

            m = i % 3

            if m == 0 :
                row_cells.append(i+1)
                row_cells.append(i+2)
            elif m == 1:
                row_cells.append(i-1)
                row_cells.append(i+1)
            else:
                row_cells.append(i-2)
                row_cells.append(i-1)

            box_1 = self.getBoxFromBoard(board[row_cells[0]])
            box_2 = self.getBoxFromBoard(board[row_cells[1]])
            box_3 = self.getBoxFromBoard(board[row_cells[2]])
        
            print(box_1,box_2,box_3)
            
        return True


inp = [ [".","8","7","6","5","4","3","2","1"],
        ["2",".",".",".",".",".",".",".","."],
        ["3",".",".",".",".",".",".",".","."],
        ["4",".",".",".",".",".",".",".","."],
        ["5",".",".",".",".",".",".",".","."],
        ["6",".",".",".",".",".",".",".","."],
        ["7",".",".",".",".",".",".",".","."],
        ["8",".",".",".",".",".",".",".","."],
        ["9",".",".",".",".",".",".",".","."]]

s = Solution()
print(s.isValidSudoku(inp))
