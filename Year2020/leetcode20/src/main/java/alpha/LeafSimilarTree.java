// Problem URL: https://leetcode.com/problems/leaf-similar-trees/
// Problem ID: 872
// Difficulty Easy
// Status: Accepted

package alpha;

import common.TreeNode;

import java.util.*;

public class LeafSimilarTree {
    private static boolean isLeafNode(TreeNode nd) {
        return nd.left == null && nd.right == null;
    }

    private static List<TreeNode> buildVisitList(TreeNode nodeRoot) {
        List<TreeNode> retValue = new ArrayList<>();
        Stack<TreeNode> visitQueue = new Stack<>();

        if( nodeRoot == null ) return retValue;
        visitQueue.add(nodeRoot);

        while(!visitQueue.isEmpty()) {
            TreeNode currentNode = visitQueue.pop();

            if( currentNode.left != null ) visitQueue.add(currentNode.left);
            if( currentNode.right != null ) visitQueue.add(currentNode.right);

            if( isLeafNode(currentNode) ) retValue.add(currentNode);
        }

        return retValue;
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        boolean retVal = true;

        var firstLeafVisit = buildVisitList(root1);
        var secondLeafVisit = buildVisitList(root2);

        int compareLength = firstLeafVisit.size();
        if( compareLength != secondLeafVisit.size() ) return false;

        for( int i=0; i<compareLength; i++ ) {
            if( firstLeafVisit.get(i).val != secondLeafVisit.get(i).val ) {
                retVal = false;
                break;
            }
        }

        return retVal;
    }
}
