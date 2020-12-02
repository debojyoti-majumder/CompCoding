// Problem URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/

type TreeNode struct {
      Val int
      Left *TreeNode
      Right *TreeNode
 }
 

func Max(x, y int) int {
    if x < y {
        return y
    }
    return x
}

func get_max_depth(node *TreeNode, current_level int) int {
    if node == nil { 
        return 0
    }
    
    left_tree_depth := get_max_depth(node.Left, current_level + 1)
    right_tree_depth := get_max_depth(node.Right, current_level + 1)
    
    return Max(left_tree_depth , right_tree_depth) + 1
}

func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    return get_max_depth(root, 0)
}
