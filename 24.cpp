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
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy, *first, *second;
        while (cur->next && cur->next->next) {
            first = cur->next;
            second = first->next;
            cur->next = second;
            first->next = second->next;
            second->next = first;
            cur = first;
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};