#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 1443
class Solution {
private:
    struct TreeNode {
        int nodeId;
        bool hasApple;
        int depth;

        TreeNode* left;
        TreeNode* right;

        TreeNode(int val, bool bApple, int d) {
            nodeId = val;
            hasApple = bApple;
            depth = d;

            left = nullptr;
            right = nullptr;
        }
    };

    // Node Id to treenode map
    map<int, TreeNode*> _treeNodes;

    void addNodeIfNotPresent(int nodeId, bool applePresent, int depth) {
        auto it = _treeNodes.find(nodeId);

        if( it == _treeNodes.end() ) {
            _treeNodes.insert(make_pair(nodeId, new TreeNode(nodeId,applePresent,depth)));
        }
    }

    void buildTree(int n, const vector<vector<int>>& edges, const vector<bool>& appleArray) {
        for( int i=0; i<edges.size(); i++ ) {
            const auto& edge{ edges[i] };

            addNodeIfNotPresent(edge[0], appleArray[i], 0);
            addNodeIfNotPresent(edge[1], appleArray[i], 0);

            auto sourceIt { _treeNodes.find(edge[0]) };
            auto destIt { _treeNodes.find(edge[1]) };

            // Updating the depth
            destIt->second->depth = sourceIt->second->depth + 1;

            if( sourceIt->second->left == nullptr ) {
                sourceIt->second->left = destIt->second;
            }
            else {
                sourceIt->second->right = destIt->second;
            }
        }
    }

    int getMinDistance(const TreeNode* node) {
        if( node == nullptr ) return 0;
        int distance = node->hasApple ? node->depth : 0;

        int leftDistance = getMinDistance(node->left);
        int rightDistance = getMinDistance(node->right);

        int num = (leftDistance + rightDistance ) * 2;
        if ( num == 0 ) return distance;
        else return num;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        _treeNodes.clear();
        buildTree(n, edges, hasApple);
        
        auto it = _treeNodes.find(0);
        if( it == _treeNodes.end() ) return 0;

        int val = getMinDistance(it->second);
        
        for( auto it : _treeNodes ) delete it.second;
        return val;
    }
};

int main() {
    vector<vector<int>> inp {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple {false,false,true,false,true,true,false};

    Solution s;
    cout << s.minTime(7, inp, hasApple) << endl;
    return 0;
}
