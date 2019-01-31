# Problem URL: https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution:
    def checkForAllOnes(self, row):
        return_value = True

        for i in range(0,len(row)):
            if row[i] == 0:
                return_value = False
                break;
        
        return return_value

    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """

        allOnesRows = []
        zeroRows = []

        for i in range(0,len(matrix)):
            if self.checkForAllOnes(matrix[i]):
                allOnesRows.append(i)
            else:
                zeroRows.append(i)
        
        # If there rows with all ones apply column rule
        if len(allOnesRows):
            # All one row index
            idx = allOnesRows[0];

            for i in range(0,len(matrix[idx])):
                zero_found = False
                
                # Searching for the zero in the column
                for k in range(0,len(matrix)):
                    if matrix[k][i] == 0:
                        zero_found = True
                        break
                
                if zero_found:
                    for k in range(0,len(matrix)):
                        matrix[k][i] = 0              
        
        # Set the zero rows
        for r in zeroRows:
            tar_row = matrix[r]
            for i in range(0,len(tar_row)):
                tar_row[i] = 0



def main():
    sol1 = Solution()
    test1 = [[1,1,1,1],[0,1,1,1],[1,0,1,1],[1,1,1,1]]
    test2 = [[-1,2,3]]
    test3 = [[-1,2,3],[0,1,1],[0,2,2]]
    
    sol1.setZeroes(test1)   # Expected output: [[0,0,0,0],[0,0,0,0],[0,0,1,1],[0,0,1,1]]
    sol1.setZeroes(test2)   # Expected output: [[-1,2,3]]
    sol1.setZeroes(test3)

    print test1
    print test2
    print test3

if __name__ == "__main__":
    main()
