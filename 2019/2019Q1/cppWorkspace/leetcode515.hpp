// Problem URL: https://leetcode.com/problems/find-largest-value-in-each-tree-row/submissions/

#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x) , left(nullptr), right(nullptr){}
};

using namespace std;

class Solution {
private:
    vector<int> _maxValues;

    // This method does a DFS
    void recusrsiveIterator(TreeNode* node, int depth = 0) {
        if( node == nullptr )
            return;

        if( _maxValues.size() <= depth ) {
            _maxValues.emplace_back(node->val);
        }

        if( _maxValues[depth] < node->val ) {
            _maxValues[depth] = node->val;
        }

        auto nextDepth = depth + 1;
        recusrsiveIterator(node->left, nextDepth);
        recusrsiveIterator(node->right, nextDepth);

        return;
    }

public:
    vector<int> largestValues(TreeNode* root) {
        _maxValues.clear();

        recusrsiveIterator(root);
        return _maxValues;     
    }
};

void testCases() {
    Solution s;

	auto nd1 = new TreeNode(1);
    auto nd2 = new TreeNode(2);
	auto nd3 = new TreeNode(3);
    auto nd4 = new TreeNode(4);
	auto nd5 = new TreeNode(5);
    auto nd6 = new TreeNode(6);
    auto nd7 = new TreeNode(7);
    auto nd8 = new TreeNode(8);
    auto nd9 = new TreeNode(9);

    nd1->left = nd3;
    nd1->right = nd2;
    nd2->right = nd9;
    nd3->left = nd5;
    nd3->right = nd8;

    auto retVals = s.largestValues(nd1);
    for(const auto& val : retVals )
        cout << val << " ";
    cout << endl;
}