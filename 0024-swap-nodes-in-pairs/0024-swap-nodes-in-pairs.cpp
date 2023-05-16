/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        while(prev->next!= NULL && prev->next->next != NULL){
            ListNode* curr = prev->next;
            ListNode* forward = curr->next;
            ListNode* temp = forward->next;
            
            prev->next = forward;
            curr->next = temp;
            forward->next = curr;
            
            prev = curr;
        }
        return dummy->next;
    }
};