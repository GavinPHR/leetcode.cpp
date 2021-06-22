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
    ListNode* sortList(ListNode* head) {
        // ListNode *p = head;
        // while (p) {
        //     cout << p->val << " ";
        //     p = p->next;
        // }
        // cout << endl;
        if (!head|| !head->next) return head;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        head2 = sortList(head2);
        ListNode dummy, *cur = &dummy;
        while (head && head2) {
            if (head->val < head2->val) {
                cur->next = head;
                head = head->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head) {
            cur->next = head;
        } else {
            cur->next = head2;
        }
        ListNode *ret = dummy.next;
        // p = ret;
        // while (p) {
        //     cout << p->val << " ";
        //     p = p->next;
        // }
        // cout << endl;
        return ret;
    }
};