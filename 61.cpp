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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int l = 0;
        ListNode *cur = head;
        while (1) {
            if (cur) ++l;
            if (cur->next) cur = cur->next;
            else {
                cur->next = head;
                break;
            }
        }
        int cut = l - k % l;
        cur = head;
        for (int i = 0; i < cut - 1; ++i) {
            cur = cur->next;
        }
        ListNode *ans = cur->next;
        cur->next = nullptr;
        return ans;
    }
};