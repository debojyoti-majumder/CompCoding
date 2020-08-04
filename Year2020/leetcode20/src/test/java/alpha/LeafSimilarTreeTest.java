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
        List<Integer> treeArray1 = Arrays.asList(3,5,1,6,2,9,8,null,null,7,4);
        List<Integer> treeArray2 = Arrays.asList(3,5,1,6,7,4,2,null,null,null,null,null,null,9,8);

        TreeNodeBuilder root1 = new TreeNodeBuilder(treeArray1);
        TreeNodeBuilder root2 = new TreeNodeBuilder(treeArray2);

        var treeOne = root1.buildTree();
        var treeTwo = root2.buildTree();

        LeafSimilarTree solver = new LeafSimilarTree();
        Assertions.assertTrue(solver.leafSimilar(treeOne, treeTwo));
    }
}
