class Solution {
public:
    inline bool reverse(ListNode *prev, ListNode *node, int k) {
        ListNode *cur = node;
        for (int i = 0; i < k; ++i) {
            if (!cur) return false;
            cur = cur->next;
        }
        ListNode *cur_prev = node;
        cur = node->next;
        for (int i = 1; i < k; ++i) {
            cur_prev->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = cur_prev->next;
        }
        return true;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *cur = head;
        while (true) {
            if (!reverse(prev, cur, k)) break;
            prev = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};
