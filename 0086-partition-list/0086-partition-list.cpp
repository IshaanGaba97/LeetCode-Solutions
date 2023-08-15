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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);
        ListNode* smallhead = smallDummy;
        ListNode* largehead = largeDummy;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                smallhead->next = temp;
                smallhead = smallhead->next;
            } else {
                largehead->next = temp;
                largehead = largehead->next;
            }
            temp = temp->next;
        }
        smallhead->next = largeDummy->next;
        largehead->next = NULL;
        return smallDummy->next;
    }
};