package alpha;

import common.TreeNode;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("Leetcode 872")
public class LeafSimilarTreeTest {
    @Test
    public void basicTest() {
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        TreeNode n3 = new TreeNode(3);
        TreeNode n4 = new TreeNode(1);
        TreeNode n5 = new TreeNode(1);
        TreeNode n6 = new TreeNode(1);
        TreeNode n7 = new TreeNode(1);
        TreeNode n8 = new TreeNode(1);

        TreeNode m1 = new TreeNode(1);
        TreeNode m2 = new TreeNode(1);
        TreeNode m3 = new TreeNode(1);
        TreeNode m4 = new TreeNode(1);

        LeafSimilarTree solver = new LeafSimilarTree();
        Assertions.assertTrue(solver.leafSimilar(m1, n1));
    }
}
