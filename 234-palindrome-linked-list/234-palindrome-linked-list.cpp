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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* headNext = head->next;
        headNext->next = head;
        head->next = NULL;
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }
        if(head->next == NULL){
            return true;
        }
        ListNode* fast = head;       
        ListNode* slow = head;      //mid
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = reverseList(slow);
        while(tail != NULL){
            if(head->val != tail->val){
                return false;
            }
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};