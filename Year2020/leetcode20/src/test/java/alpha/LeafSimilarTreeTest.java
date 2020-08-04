package alpha;

import common.TreeNode;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@DisplayName("Leetcode 872")
public class LeafSimilarTreeTest {
    @Test
    public void basicTest() {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        TreeNode node6 = new TreeNode(6);
        TreeNode node7 = new TreeNode(7);
        TreeNode node8 = new TreeNode(8);
        TreeNode node9 = new TreeNode(9);

        node3.left = node5; node3.right = node1;
        node5.left = node6; node5.right = node2;
        node2.left = node7; node2.right = node4;
        node1.left = node9; node1.right = node8;

        TreeNode m1 = new TreeNode(1);

        List<Integer> treeArray1 = Arrays.asList(3,5,1,6,2,9,8,null,null,7,4);
        List<Integer> treeArray2 = Arrays.asList(3,5,1,6,7,4,2,null,null,null,null,null,null,9,8);

        TreeNodeBuilder root1 = new TreeNodeBuilder(treeArray1);
        TreeNodeBuilder root2 = new TreeNodeBuilder(treeArray2);
        /*
        * [3,5,1,6,2,9,8,null,null,7,4]
        * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
        * */

        root1.buildTree();
        root2.buildTree();

        LeafSimilarTree solver = new LeafSimilarTree();
        Assertions.assertTrue(solver.leafSimilar(node3, m1));
    }
}
