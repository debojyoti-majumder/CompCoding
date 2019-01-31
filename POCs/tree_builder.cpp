// Includes for the library
#include <vector>
#include <queue>
#include <iostream>

typedef struct _TreeNode {
    int value;
    struct _TreeNode* left;
    struct _TreeNode* right;

    _TreeNode(int v) : value(v), left(nullptr) , right(nullptr) {}

    // Just for debugging purpose
    ~_TreeNode() {
        std::cout << "The node " << value << " freed." << std::endl;
    }
}TreeNode;

class MyTreeNode {
    private:
        TreeNode* tree_root;
    protected:
        void outputPreorder(TreeNode* root) {
            if( root != nullptr ) {
                std::cout << root->value << " ";
                outputPreorder(root->left);
                outputPreorder(root->right);
            }
        }
        
        // Will deallocate memory 
        void destroyTree(TreeNode* node) {
            if( node != nullptr ) {
                // Saving the address
                auto left = node->left;
                auto right = node->right;

                // Freing the up memeory
                delete node;

                // Recusring the destroy
                destroyTree(left);
                destroyTree(right);
            }
        }

    public:
        MyTreeNode() = delete;
        MyTreeNode(std::vector<int> tree_array) : tree_root(nullptr) {
            auto list_size = tree_array.size();
            std::queue<TreeNode*> node_queue;

            if( list_size == 0 )
                return;
    
            // Intialize the root and add to the queue
            tree_root = new TreeNode(tree_array[0]);
            node_queue.push(tree_root);
            
            // Going through each node to build the tree
            for(size_t i=0; i<list_size; i++) {
                // Getting the index of the child items
                size_t left_child = 2*i + 1;
                size_t right_child = 2*i + 2;

                // Something must have gone wrong, can't go ahead
                if( node_queue.empty() )
                    break;

                // Getting the current node from the queue
                auto current_node = node_queue.front();
                node_queue.pop();

                if( current_node == nullptr )
                    continue;

                // Adding the childs
                if( left_child < list_size ) {
                    auto new_node = new TreeNode(tree_array[left_child]);
                    node_queue.push(new_node);
                    current_node->left = new_node;
                }

                if( right_child < list_size ) {
                    auto new_node = new TreeNode(tree_array[right_child]);
                    node_queue.push(new_node);
                    current_node->right = new_node;
                }
            }
        } 

        void print() {
            outputPreorder(tree_root);
            std::cout << std::endl;
        }

        ~MyTreeNode() {
            destroyTree(tree_root);
        }
};

// Test program
int main() {
    // Building the tree
    MyTreeNode main_tree(std::vector<int>{9,6,6,3,5,6,9});

    // Displaying the items
    main_tree.print();

    return 0;
}
