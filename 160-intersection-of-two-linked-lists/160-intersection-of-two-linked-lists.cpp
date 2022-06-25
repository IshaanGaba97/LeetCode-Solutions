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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int sizeA = 1;
        int sizeB = 1;
        while(tempA != nullptr){
            tempA = tempA->next;
            sizeA++;
        }
        while(tempB != nullptr){
            tempB = tempB->next;
            sizeB++;
        }
        int ressize = abs(sizeA - sizeB);
        if(sizeA > sizeB){
            for(int i = 0; i < ressize; i++)
                headA = headA->next;
        } else {
            for(int i = 0; i < ressize; i++)
                headB = headB->next;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};