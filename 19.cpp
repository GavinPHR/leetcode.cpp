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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = dummy, *second = dummy;
        for (int i = 0; i < n; ++i) second = second->next;
        while (second->next) {
            first = first->next;
            second = second->next;
        }
        ListNode *to_delete = first->next;
        first->next = first->next->next;
        delete to_delete;

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};