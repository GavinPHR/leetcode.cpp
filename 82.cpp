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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur) {
            ListNode *n = cur->next;
            if (!n || !n->next) break;
            ListNode *nn = n->next;
            if (n->val == nn->val) {
                int val = n->val;
                ListNode *to_delete = n;
                while (to_delete && to_delete->val == val) {
                    ListNode *tmp = to_delete->next;
                    delete to_delete;
                    to_delete = tmp;
                }
                cur->next = to_delete;
            } else {
                cur = cur->next;
            }
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};
