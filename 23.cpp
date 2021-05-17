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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heap;
        for (auto &l : lists) {
            if (l) heap.push_back(l);
        }
        auto cmp = [](ListNode *a, ListNode *b) {return a->val > b-> val;};
        make_heap(heap.begin(), heap.end(), cmp);
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while (!heap.empty()) {
            pop_heap(heap.begin(), heap.end(), cmp);
            cur->next = heap.back();
            // cout << heap.back()->val << " ";
            heap.pop_back();
            if (cur->next->next != nullptr) {
                heap.push_back(cur->next->next);
                push_heap(heap.begin(), heap.end(), cmp);
            }
            cur = cur->next;
        }
        ListNode *res = dummy->next;
        delete dummy;
        // for (auto n : heap) cout << n->val << " ";
        return res;
    }
};