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
    int pairSum(ListNode* head) {
        ListNode* node = head;
        stack<int> st;
        int n = 0;
        while(node != NULL){
            st.push(node->val);
            node = node->next;
            n++;
        }
        
        int ans = -1e9;
        while(st.size() > n/2){
            int temp = st.top(); st.pop();
            int sum = temp + head->val;
            ans = max(ans, sum);
            head=head->next;
        }
        return ans;
    }
};