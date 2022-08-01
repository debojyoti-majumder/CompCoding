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
        public int x;
        public int y;
        private List<VisitBox> visitBacktracking;

        public VisitBox(int x, int y) {
            this.x = x;
            this.y = y;

            this.visitBacktracking = new ArrayList<>();
        }

        public List<VisitBox> getAdjacentBoxes(int m, int n) {
            List<VisitBox> adjcItems = new ArrayList<>();

            if( x > 0 ) adjcItems.add(new VisitBox(this.x - 1, this.y));
            if( x < m -1 ) adjcItems.add(new VisitBox(this.x + 1, this.y));
            if( y > 0 ) adjcItems.add(new VisitBox(this.x, this.y - 1));
            if( y < n -1 ) adjcItems.add(new VisitBox(this.x, this.y + 1));

            return adjcItems;
        }

        public boolean visit(VisitBox b) {
            var selfLoop = b.visitBacktracking.stream()
                .filter(obj ->  obj.x == this.x && obj.y == this.y)
                .findFirst();
            
            if( selfLoop.isPresent() ) return false;

            Optional<VisitBox> alreadyVisited = this.visitBacktracking.stream()
                .filter(obj ->  obj.x == b.x && obj.y == b.y)
                .findFirst();
            
            // This means this is new path tha
            if( !alreadyVisited.isPresent() ) {
                this.visitBacktracking.add(b);
                return true;
            }
            else {
                return false;
            }
        }

        public boolean isDestination(int m, int n) {
            return this.x == m && this.y == n;
        }
    }

    private VisitBox[][] inputMatrix;
    
    private VisitBox[][] buildVisitBox(int m, int n) {
        VisitBox[][] cellMatrix = new VisitBox[m][n];
        for( int i=0; i<m; i++ ) {
            for( int j=0; j<n; j++) {
                cellMatrix[i][j] = new VisitBox(i, j);
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
            VisitBox box = visitQueue.poll();
            
            // Iterating through it's nodes
            var linkedItems = box.getAdjacentBoxes(m, n);

            // Any newly linked node should be visited
            for( var lnk : linkedItems ) {
                boolean isNewNode = lnk.visit(box);
                if( isNewNode ) visitQueue.add(lnk);
            }

            // We have found new path to go
            if( box.isDestination(m, n) ) uniquePathCount += 1;
        }
        
        return uniquePathCount;
    }
}
