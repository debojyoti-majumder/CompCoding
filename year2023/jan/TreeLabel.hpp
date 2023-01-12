#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    struct TreeNode {
        int nodeId;

        int leftIndex;
        int rightIndex;

        char label;
        map<char,int> labelMap;

        TreeNode(int id, char l) {
            nodeId = id;
            leftIndex = -1;
            rightIndex = -1;
            label = l;
            labelMap.insert(make_pair(l, 1));
        }
    };

    vector<TreeNode> _treeNodes;

    void buildTreeFromEdges(int n, vector<vector<int>>& edges, string labels) {
        _treeNodes.clear();
        for(int i=0; i<n; i++) _treeNodes.emplace_back(TreeNode(i, labels[i]));

        for( const auto& edge : edges ) {
            int sourceIndex = edge[0];
            int targetIndex = edge[1];

            if( _treeNodes[sourceIndex].leftIndex == -1 ) _treeNodes[sourceIndex].leftIndex = targetIndex;
            else _treeNodes[sourceIndex].rightIndex = targetIndex;
        }
    }

    void mergeValueMap(TreeNode& node, TreeNode child) {
        for( auto& labVal : child.labelMap ) {
            auto it = node.labelMap.find(labVal.first);
                
            if( it != node.labelMap.end() ) 
                it->second += labVal.second;
            else
                node.labelMap.insert(make_pair(labVal.first, labVal.second));
        }
    }

    void makeCountMap(TreeNode& nd) {
        if( nd.leftIndex != -1 ) { 
            TreeNode& leftChild { _treeNodes[nd.leftIndex] };
            
            makeCountMap(leftChild);
            mergeValueMap(nd, leftChild);
        }

        if( nd.rightIndex != -1 ) {
            TreeNode& rightChild { _treeNodes[nd.rightIndex] };
            
            makeCountMap(rightChild);
            mergeValueMap(nd, rightChild);
        }
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        buildTreeFromEdges(n, edges, labels);

        // Building the maps from root
        TreeNode& root{ _treeNodes[0] };
        makeCountMap(root);
        
        vector<int> labelCounts;
        for( const auto& nd : _treeNodes ) {
            auto it = nd.labelMap.find(nd.label);
            labelCounts.emplace_back(it->second);
        }

        return labelCounts;        
    }
};

void test1519() {
    vector<vector<int>> ed1 {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};

    Solution s;
    auto ret { s.countSubTrees(7, ed1, "abaedcd") };
    for( const auto& val : ret ) cout << val << " ";
    cout << endl;

    vector<vector<int>> ed2 {{0,1},{1,2}, {0,3}};
    ret = s.countSubTrees(4, ed2, "bbbb");
    for( const auto& val : ret ) cout << val << " ";
    cout << endl;

    vector<vector<int>> ed3 {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6}};
    ret = s.countSubTrees(7, ed3, "aaabaaa");
    for( const auto& val : ret ) cout << val << " ";
    cout << endl;
}

int main() {
    test1519();
    return 0;
}
