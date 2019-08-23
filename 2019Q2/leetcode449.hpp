// Problem URL: https://leetcode.com/problems/serialize-and-deserialize-bst/

#include "pch.h"
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return "";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return nullptr;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* nd1 = new TreeNode(2);
    TreeNode* nd2 = new TreeNode(3);

    root->left = nd1;
    root->right = nd2;

    nd1->left = new TreeNode(4);
    nd2->right = new TreeNode(5);

    Codec codec;
    codec.deserialize(codec.serialize(root));

    return 0;
}
