// Leet code probelm id 310
// Tried to build depth of the tree incrementally but not able to pass all the test cases
// The main problem was I was not able to update the depth of the tree of the third test case 

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
private:
    vector<TreeNode*>   _children;
    unsigned int        _depth;
    int                 _id;

    void updateDepth(TreeNode* caller) {
        _depth += 1;
        
        for( auto child: _children ) {
            if( child != caller )
                child->updateDepth(this);
        }
    }

public:
    TreeNode(int i) : _id(i) , _depth(0) {}
    
    // Should increament the depth of the children
    void addChild(TreeNode* nd) {
        // Updating the new node
        nd->_depth = _depth + 1;
        nd->_children.push_back(this);

        // Incremnting the depth of the children
        for( auto c:_children ) {
            if( nd->_depth > c->_depth )
                c->updateDepth(this);
        }

        _children.push_back(nd);
    }

    void initChild(TreeNode* nd) {
        _children.push_back(nd);
        _depth = 1;
    }

    auto getDepth() const { return _depth; }
    auto getId() const { return _id; }
    auto childCount() const { return _children.size(); }
};

class Solution {
private:
    vector<TreeNode*> _nodes;

public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        for(auto i=0; i<n; i++) 
            _nodes.push_back(new TreeNode(i));

        // While adding the edge the depths needs to be calculated
        for(auto e : edges) {
            auto nd_1 = _nodes[e.first];
            auto nd_2 = _nodes[e.second];
            
            auto ch_1 = nd_1->childCount();
            auto ch_2 = nd_2->childCount();
            
            TreeNode *old_node = nullptr;
            TreeNode *new_node = nullptr;

            // Base case
            if( ch_1 == ch_2 && ch_1 == 0 ) {
                nd_1->initChild(nd_2);
                nd_2->initChild(nd_1);

                // Edge already created
                continue;
            }
            else if( ch_2 == 0 ) {
                old_node = nd_1;
                new_node = nd_2;
            }
            else {
                old_node = nd_2;
                new_node = nd_1;
            }

            // Adding the edge with the tree
            old_node->addChild(new_node);
        }
        
        auto min_depth = _nodes[0]->getDepth();
        auto ret_value = vector<int>();

        // Find out the minimum
        for(auto i=0; i<n; i++) {
            auto d = _nodes[i]->getDepth();
            if( d <= min_depth )
                min_depth = d;
        }

        // Populate the minimum value
        for( auto p : _nodes ) {
            if( min_depth == p->getDepth() ) 
                ret_value.push_back(p->getId());
        }   

        return ret_value;
    }
};
