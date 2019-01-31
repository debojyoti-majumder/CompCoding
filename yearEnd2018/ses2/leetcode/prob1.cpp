// Problem url: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // To handle empty lists
        if( head == nullptr )   return head;
        
        auto prevNode = head;
        auto iterator = head->next;
        
        while( iterator ) {
            auto tmp = iterator;
            
            if( tmp->val == prevNode->val ) {
                prevNode->next = tmp->next;
                delete tmp;
            }
            else 
                prevNode = tmp;
            
            iterator = iterator->next;
            
        }
        
        return head;
    }
};
