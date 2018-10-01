#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;

    Node() : value(0), next(nullptr) {}
    explicit Node(T v) : value(v) , next{nullptr} {}
};

template <typename T>
class LinkList {
    private:
        Node<T> *head;
        Node<T> *current;
        int sz;

    public:
        LinkList() : head{nullptr} , current{nullptr}, sz{0}{}
        
        void addItem(T item) {
            if( head != nullptr ) {
                current->next = new Node<T>(item);
                current = current->next;
            }
            else {
                head = new Node<T>(item);
                current = head;
            }

            ++sz;
        }

        friend ostream& operator<<(ostream& out, const LinkList& list) {
            out << "[ ";
            auto nd = list.head;
            while( nd != nullptr ) {
                cout << nd->value << " ";
                nd = nd->next; 
            }
            out << "]";
            return out;
        }

        T getItemAt(size_t pos) {
            if( pos > sz )
                throw "Array out of index";
            
            auto cursor = head;
            for( size_t i=0; i<pos; ++i) {
                cursor = cursor->next;
            }

            return cursor->value;
        }

        T& operator[] (size_t pos) {
            if( pos > sz )
                throw "Array out of index";
            
            auto cursor = head;
            for( size_t i=0; i<pos; ++i) {
                cursor = cursor->next;
            }
            
            return cursor->value;
        }

        class iterator {
            private:
                Node<T>* node;

            public:
                iterator(Node<T>* nd) : node{nd} {}

                void operator++() {
                    node = node->next;
                }

                Node<T>& operator->() {
                    return *(node);
                }

                bool operator!=(const iterator& other) {
                    return this->node != other.node;
                }
        };

        iterator begin() {
            return iterator{head};
        }

        iterator end() {
            return iterator{nullptr};
        }

        ~LinkList() {
            auto nd = head;
            while( nd ) {
                delete nd;
                head = nd = head->next;
            }

            head = nullptr;
        }
};

struct Person {
    string firstName;
    string lastName;

    friend ostream& operator<<(ostream& out, const Person& r) {
        out << r.firstName << r.lastName;
        return out;
    }
};

int main() {
    LinkList<int> myList;
    LinkList<Person> persons;

    for(int i=0; i<10; i++) { 
        myList.addItem((i+1) * 10);
        persons.addItem(Person{
            string{"FirstName"}, 
            string{"lastname"}
        });
    }

    cout << myList << '\n';
    cout << myList.getItemAt(5) << '\n';
    myList[5] = 55;
    cout << myList[5] << '\n';
    cout << myList << '\n';

    cout << persons << endl;
    persons[5] = Person{"Debojyoti", "Majumder"};
    cout << persons << endl;

    auto copy{myList};
    cout << copy << endl;
    cout << myList << endl;

    for(auto it=myList.begin(); it != myList.end(); ++it) {
        cout << "Wow" << endl;
    }

    return 0;
}
