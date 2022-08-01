/* 
 * Problem URL : https://leetcode.com/problems/unique-paths/
 * Status : Impl in progress
 */
package org.debojyotim.aug;

import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Optional;

public class UniquePath {
    private static class VisitBox {
        private int x;
        private int y;
        private List<VisitBox> visitBacktracking;
        public int nodeID;

        public VisitBox(int x, int y, int n) {
            this.nodeID = x*n + y + 1;
            this.visitBacktracking = new ArrayList<>();
        }

        public List<VisitBox> getAdjacentBoxes(int m, int n) {
            List<VisitBox> adjcItems = new ArrayList<>();

            if( y > 0 ) adjcItems.add(new VisitBox(this.x, this.y - 1,n));
            if( y < n - 1 ) adjcItems.add(new VisitBox(this.x, this.y + 1,n));
            if( x < m - 1 ) adjcItems.add(new VisitBox(this.x + 1, this.y,n));
            if( x > 0 ) adjcItems.add(new VisitBox(this.x - 1, this.y,n));

            return adjcItems;
        }

        public boolean visit(VisitBox b) {
            this.visitBacktracking = b.visitBacktracking;
            Optional<VisitBox> selfItem = this.visitBacktracking.stream()
                .filter(obj -> obj.nodeID == b.nodeID)
                .findFirst();
            
            return selfItem.isEmpty();
        }

        public boolean isDestination(int m, int n) {
            return this.x == m-1 && this.y == n-1;
        }
    }

    private VisitBox[][] inputMatrix;
    
    private VisitBox[][] buildVisitBox(int m, int n) {
        VisitBox[][] cellMatrix = new VisitBox[m][n];
        for( int i=0; i<m; i++ ) {
            for( int j=0; j<n; j++) {
                cellMatrix[i][j] = new VisitBox(i, j, n);
            }
        }

        return cellMatrix;
    }

    public int uniquePaths(int m, int n) {
        int uniquePathCount = 0;
        this.inputMatrix = buildVisitBox(m, n);
        Queue<VisitBox> visitQueue = new LinkedList<>();

        // Some validation
        if( m == 0 || n == 0 ) return 0;
        
        // This is the starting point 
        visitQueue.add(this.inputMatrix[0][0]);
        while(visitQueue.isEmpty() == false) {
            VisitBox currentItem = visitQueue.poll();
            
            // If destination is reach no need to look for further nodes
            if( currentItem.isDestination(m, n) ) {
                uniquePathCount += 1;
                continue;
            }

            // Iterating through it's nodes, these are just simple 
            // indexes does not mean anything
            var linkedItems = currentItem.getAdjacentBoxes(m, n);

            // Any newly linked node should be visited
            for( var lnk : linkedItems ) {
                boolean isNewNode = lnk.visit(currentItem);
                if( isNewNode ) {
                    visitQueue.add(lnk);
                }
            }
        }
        
        return uniquePathCount;
    }
}
