// Includes for the library
#include <vector>
#include <queue>
#include <iostream>

typedef struct _TreeNode {
    int value;
    struct _TreeNode* left;
    struct _TreeNode* right;

    _TreeNode(int v) : value(v), left(nullptr) , right(nullptr) {}
}TreeNode;

// Accepts a lis of integers and builds the tree
TreeNode* buildTreeNodeFromArray(std::vector<int> node_list) {
    TreeNode *node = nullptr;
    auto list_size = node_list.size();
    std::queue<TreeNode*> node_queue;

    if( list_size == 0 )
        return nullptr;
    
    // Intialize the root
    node = new TreeNode(node_list[0]);
    node_queue.push(node);

    for(size_t i=0; i<list_size; i++) {
        // Getting the index of the child items
        size_t left_child = 2*i + 1;
        size_t right_child = 2*i + 2;

        // Something must have gone wrong, can't go head
        if( node_queue.empty() )
            break;

        // Getting the current node from the queue
        auto current_node = node_queue.front();
        node_queue.pop();

        if( current_node == nullptr )
            continue;

        // Adding the childs
        if( left_child < list_size ) {
            auto new_node = new TreeNode(node_list[left_child]);
            node_queue.push(new_node);
            current_node->left = new_node;
        }

        if( right_child < list_size ) {
            auto new_node = new TreeNode(node_list[right_child]);
            node_queue.push(new_node);
            current_node->right = new_node;
        }
    }

    return node;
}

// Will deallocate memory 
void destroyTree(TreeNode* root) {

}

void outputPreorder(TreeNode* root) {

}

// Test program
int main() {
    std::vector<int> ndArray{2,3,4,5,6,7,9};
    
    // Building the tree
    auto root = buildTreeNodeFromArray(ndArray);

    // Destroying the tree
    destroyTree(root);
    return 0;
}
