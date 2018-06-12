/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void deleteInRange(ListNode* left, ListNode* right) {
        if( left != nullptr && right != nullptr ) {
            cout << left->val << " " << right->val << endl;
        }
        
        return;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == nullptr ) return nullptr;
        
        auto iterator = head->next;
        auto prevNode = head;
        
        ListNode* start = nullptr;
        ListNode* end = nullptr;
        
        while( iterator ) {
            if( prevNode->val == iterator->val ) {   
                if( start == nullptr ) 
                    start = prevNode;
                else
                    end = iterator;
            }
            else {
                if( start == head ) head = end->next;
                deleteInRange(start, end);
                
                start = nullptr;
                end = nullptr;
            }
            
            prevNode = iterator;
            iterator = iterator->next;
        }
        
        return head;
    }
};
