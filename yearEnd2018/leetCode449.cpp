// Problem URL: https://leetcode.com/problems/serialize-and-deserialize-bst/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    private:
        vector<string> _treeTokens;

        void buildTokens(TreeNode* nd, int pos = 0) {
            if( nd != nullptr ) {
                auto leftChildIndex = 2*pos + 1;
                auto rightChildIndex = 2*pos + 2;

                if( rightChildIndex > _treeTokens.size() )
                    _treeTokens.resize(rightChildIndex, "NULL");
                
                stringstream ss;
                ss << nd->val;
                _treeTokens[pos] = ss.str();

                buildTokens(nd->left, leftChildIndex);
                buildTokens(nd->right, rightChildIndex);
            }
            else {
                _treeTokens[pos] = "NULL";
            }
        }

    public:
        string encodeTreeNode(TreeNode* root) {
            buildTokens(root);
            string accString = "";

            for( const auto& s : _treeTokens ) {
                accString += s;
                accString += ",";
            }
            
            _treeTokens.erase(begin(_treeTokens), end(_treeTokens));
            return accString.substr(0, accString.size()-1);
        }    

        TreeNode* decodeTreeNode(string data) {
            stringstream dataStream(data);
            vector<string> tokens;
            string tmp;

            while(getline(dataStream, tmp, ','))
                tokens.emplace_back(tmp);
            
            auto sz = tokens.size();
            TreeNode* retValue = nullptr;

            for( auto i=0; i<sz; i++ ) {
                auto val = stoi(tokens[i]);
                auto nd = new TreeNode(val);

                if( i == 0 )
                    retValue = nd;

                auto leftChildIndx = 2*i + 1;
                auto rightChildIndex = 2*i + 2;

                if( leftChildIndx < sz && tokens[leftChildIndx] != "NULL" )
                    nd->left = new TreeNode(stoi(tokens[leftChildIndx]));
                
                if( rightChildIndex < sz && tokens[rightChildIndex] != "NULL")
                    nd->right = new TreeNode(stoi(tokens[rightChildIndex]));
            }

            return retValue;
        }
};

// This is inorder traversal
void printTreeNode(TreeNode* nd) {
    if( nd != nullptr ) {
        printTreeNode(nd->left);
        cout << nd->val << " ";
        printTreeNode(nd->right);
    }
}

int main() {
    Codec c;
    
    // nd0 will be the root node
    TreeNode nd0(0), nd1(1), nd2(2), nd3(3), nd4(4);
    nd0.left = &nd1;
    nd0.right = &nd2;
    nd1.left = &nd3;
    nd2.right = &nd4;

    // Doing encoding and decoding
    auto encodedData = c.encodeTreeNode(&nd0);
    cout << encodedData << endl;

    auto treeNode = c.decodeTreeNode(encodedData);
    
    // Both output should be same
    printTreeNode(&nd0);
    cout << endl;
    printTreeNode(treeNode);
    cout << endl;

    return 0;
}
