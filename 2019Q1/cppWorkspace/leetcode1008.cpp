/*
    Problem URL:    https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/
    Problem ID:     1008
    Issue ID:       31   

    Related Problem:
        https://leetcode.com/problems/distribute-coins-in-binary-tree/
        https://leetcode.com/problems/path-sum-ii/
*/

#include <iostream>
#include <vector>

using namespace std;

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if( preorder.size() == 0 ) return nullptr;

        auto rootNode = new TreeNode(preorder[0]);
        vector<int> leftSideOfTree;
        vector<int> rightSideOfTree;

        for( size_t i=1; i<preorder.size(); i++ ) {
            if( preorder[i] < preorder[0] ) 
                leftSideOfTree.emplace_back(preorder[i]);
            else
                rightSideOfTree.emplace_back(preorder[i]);
        }

        rootNode->left = bstFromPreorder(leftSideOfTree);
        rootNode->right = bstFromPreorder(rightSideOfTree);
        return rootNode;
    }
};

int main() {
    return 0;
}
