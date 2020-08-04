package alpha;

import common.TreeNode;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TreeNodeBuilder {
    private List<Integer> treeArray;
    private Map<Integer, TreeNode> nodeMap = new HashMap<>();

    public TreeNodeBuilder(List<Integer> arrayRep) {
        treeArray = arrayRep;
    }

    private TreeNode getLeftNode(int index) {
        int n = index + 1;
        int leftIndex = 2*n - 1;

        if( leftIndex >= treeArray.size() ) return null;

        Integer idx = treeArray.get(leftIndex);
        return idx != null ? nodeMap.get(leftIndex) : null;
    }

    private TreeNode getRightNode(int index) {
        int n = index + 1;
        int rightIndex = 2*n;

        if( rightIndex >= treeArray.size() ) return null;

        Integer idx = treeArray.get(rightIndex);
        return idx != null ? nodeMap.get(rightIndex) : null;
    }

    public TreeNode buildTree() {
        if( treeArray.size() == 0 ) return null;

        for( int i=0; i<treeArray.size(); i++ ) {
            var item = treeArray.get(i);

            if( item != null ) {
                nodeMap.put(i, new TreeNode(item));
            }
        }

        for( var entry : nodeMap.entrySet() ) {
            var nodeIndex = entry.getKey();
            var node = entry.getValue();

            node.left = getLeftNode(nodeIndex);
            node.right = getRightNode(nodeIndex);
        }

        // The 1st element is the root
        return nodeMap.get(0);
    }
}
