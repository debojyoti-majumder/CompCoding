package alpha;

import common.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class TreeNodeBuilder {
    private List<Integer> treeArray;

    public TreeNodeBuilder(List<Integer> arrayRep) {
        treeArray = arrayRep;
    }

    public TreeNode buildTree() {
        if( treeArray.size() == 0 ) return null;

        List<TreeNode> nodes = new ArrayList<>();
        for (Integer integer : treeArray) {
            if( integer != null) nodes.add(new TreeNode(integer));
        }

        // The zero node is the root
        return nodes.get(0);
    }
}
