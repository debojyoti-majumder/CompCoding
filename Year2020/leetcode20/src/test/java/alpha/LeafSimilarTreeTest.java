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
        TreeNode m1 = new TreeNode(1);

        /*
        * [3,5,1,6,2,9,8,null,null,7,4]
        * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
        * */
        LeafSimilarTree solver = new LeafSimilarTree();
        Assertions.assertTrue(solver.leafSimilar(m1, n1));
    }
}
