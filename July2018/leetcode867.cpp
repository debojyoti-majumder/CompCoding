struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    int getLength(ListNode* head) {
        auto it = head;
        int len = 0;
        
        while( it ) {
            len++;
            it = it->next;
        }

        return len;
    }

    ListNode* getAt(ListNode* head, int pos) {
        auto it = head;

        for( auto i=0; i<pos; i++ ) {
            // This is just for safe gaurd
            if( it == nullptr )
                return nullptr;

            it = it->next;
        }

        return it;
    }
public:
    ListNode* middleNode(ListNode* head) {
        auto len = getLength(head);
        int m = len / 2;

        return getAt(head,m);       
    }
};
