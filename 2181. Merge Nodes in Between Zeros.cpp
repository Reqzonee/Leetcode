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
    ListNode* Newhead;
    void helper(ListNode* head, int sum){
        if(!head){
            return;
        }

        if(head->val == 0){
            ListNode* temp = new ListNode(sum);
            Newhead->next = temp;
            Newhead=temp;

            sum = 0;
        }
        helper(head->next, sum+head->val);
    }
    ListNode* mergeNodes(ListNode* head) {
        Newhead = new ListNode(0);
        ListNode* ans = Newhead;
        int sum = 0;
        helper(head, sum);
        return ans->next->next;
    }
};