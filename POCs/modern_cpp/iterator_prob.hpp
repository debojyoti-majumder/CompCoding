#include <iostream>
#include <string>

using namespace std;

template <typename T> struct BinaryTree;

template <typename T> struct Node {
    T value;

    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    Node<T>* parent = nullptr;

    BinaryTree<T>* tree = nullptr;

    explicit Node(const T& v) : value(v) {
    }

    Node(const T& v, Node<T>* const l, Node<T>* const r) : value(v) , left(l), right(r) {
        left->parent = right->parent = this;
        this->left->tree = this->right->tree = tree;
    }

    void setTree(BinaryTree<T>* p) {
        tree = p;

        if( left )  left->setTree(p);
        if( right ) right->setTree(p);
    }
};

template <typename T> struct PreOrderTraversal;

template <typename T> struct BinaryTree {
    Node<T>* root = nullptr;

    explicit BinaryTree(Node<T>* const root) : root(root) {
        root->setTree(this);
    }

    PreOrderTraversal<T> begin() {
        Node<T> *n = root;

        if (n)
            while (n->left)
                n = n->left;

        return PreOrderTraversal<T>{n};
    }

    PreOrderTraversal<T> end() {
        return PreOrderTraversal<T>{nullptr};
    }
};

template <typename T> struct PreOrderTraversal {
    Node<T>* current;

    explicit PreOrderTraversal(Node<T>* current) : current(current) {

    }

    bool operator !=(const PreOrderTraversal<T>& rhs) {
        return current != rhs.current;
    }

    Node<T>& operator*(){
        return *current;
    }

    PreOrderTraversal<T> &operator++() {
        if (current->right) {
            current = current->right;
            while (current->left)
                current = current->left;
        }
        else {
            Node<T> *p = current->parent;
            while (p && current == p->right) {
                current = p;
                p = p->parent;
            }
            current = p;
        }
        return *this;
    }
};

int main(int argc, char const *argv[]) {
    auto cdrive = new Node<string>{"Cdrive",
        new Node<string>{"Folder1"},
        new Node<string>{"Folder2"}
    };

    auto ddrive = new Node<string>{"Cdrive",
        new Node<string>{"Folder1"},
        new Node<string>{"Folder2"}
    };

    auto root = new Node<string>{"root",cdrive, ddrive};

    BinaryTree<string> tree{root};

    for(auto it = tree.begin(); it != tree.end(); ++it ) {
        cout << (*it).value << " ";
    }

    // TODO: Use smart pointers later
    delete root;
    delete ddrive;
    delete cdrive;

    cout << endl;
    return 0;
}
