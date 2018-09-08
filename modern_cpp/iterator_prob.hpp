#include <iostream>
#include <string> 
template <typename T> class BinaryTree;

template <typename T> struct Node {
    T value;
    
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    Node<T>* parent = nullptr;

    BinaryTree<T>* tree = nullptr;

    explicit Node(const T& val) : value(val) {
    }

    Node(const T& val, Node<T>* const l, Node<T>* const r) : value(val), left(l), right(r) {
        left->tree = right->tree = tree;
        left->parent = right->parent = this;
    }

    void setTree(BinaryTree<T>* const tr) {
        this->tree = tr;

        // This will workout recusively
        if( left )  this->left->setTree(tr);
        if( right ) this->right->setTree(tr);
    }
};

template <typename U> struct PreOrderInerator {
    Node<U>* current;

    explicit PreOrderInerator(Node<U>* current) : current(current) {

    }

    bool operator != (const PreOrderInerator<U>& rhs) {
        return current != rhs.current;
    }

    Node<U>& operator*() {
        return *current;
    }

    PreOrderInerator<U>& operator++() {
        if( current->right ) {
            current = current->right;

            while( current->left )
                current = current->left;
        }
        else {
            auto p = current->parent;
            while( p && current == p->right ) {
                current = p;
                p = p->parent;
            }

            current = p;
        }

        return *this;
    }
};

template <typename T> using iterator = PreOrderInerator<T>;

template <typename T> struct BinaryTree {
    Node<T>* root = nullptr;

    explicit BinaryTree(Node<T>* const r) : root{r} {
        r->setTree(this);
    }

    iterator<T> begin() {
        Node<T>* n = root;
        if(n) {
            while( n->left ) n = n->left;
        }

        return iterator<T>{n};
    }

    iterator<T> end() {
        return iterator<T>{ nullptr };
    }
};


int main(int argc, char const *argv[]) {
    auto nd = new Node<string>("dad");

    return 0;
}
