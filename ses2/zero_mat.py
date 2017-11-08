# Problem URL: https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution:
    def setZeroes(self, matrix):
        print "Calling set zero function"
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """

def main():
    sol1 = Solution()
    test1 = [[0,1,1,1],[1,0,1,1],[1,1,1,1],[1,1,1,1]]  
    sol1.setZeroes(test1) # Expected output: [[0,0,0,0],[0,0,0,0],[0,0,1,1],[0,0,1,1]]

if __name__ == "__main__":
    main()
