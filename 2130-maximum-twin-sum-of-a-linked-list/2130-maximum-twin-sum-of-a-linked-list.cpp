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
        vector<int> v;
        ListNode* node = head;
        while(node != NULL){
            v.push_back(node->val);
            node = node->next;
        }
        int n = v.size();
        int i = 0;
        int j = n-1;
        int maxi = -1e9;
        while(i < j){
            int sum = v[i] + v[j];
            maxi = max(maxi, sum);
            i++; j--;
        }
        return maxi;
    }
};