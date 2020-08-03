// Problem URL: https://leetcode.com/problems/leaf-similar-trees/
// Problem ID: 872
// Difficulty Easy
// Status: Not Impl

package alpha;

import common.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeafSimilarTree {
    private static boolean isLeafNode(TreeNode nd) {
        return nd.left == null && nd.right == null;
    }

    private List<TreeNode> buildVisitList(TreeNode nodeRoot) {
        List<TreeNode> retValue = new ArrayList<>();
        Queue<TreeNode> visitQueue = new LinkedList<>();

        if( nodeRoot == null ) return retValue;
        visitQueue.add(nodeRoot);

        while(!visitQueue.isEmpty()) {
            TreeNode currentNode = visitQueue.remove();

            if( currentNode.left != null ) visitQueue.add(currentNode.left);
            if( currentNode.right != null ) visitQueue.add(currentNode.right);

            if( isLeafNode(currentNode) ) retValue.add(currentNode);
        }

        return retValue;
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        var firstLeafVisit = buildVisitList(root1);
        var secondLeafVisit = buildVisitList(root2);

        int compareLength = firstLeafVisit.size();
        if( compareLength != secondLeafVisit.size() ) return false;

        for( int i=0; i<compareLength; i++ ) {
            if( firstLeafVisit.get(i).val != secondLeafVisit.get(i).val ) return false;
        }

        return true;
    }
}
