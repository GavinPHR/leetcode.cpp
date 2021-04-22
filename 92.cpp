#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        int cur_idx = 0;
        ListNode* cur = dummy;
        while (cur_idx != left - 1) {
            cur = cur->next;
            ++cur_idx;
        }
        ListNode* before_left_node = cur;
        ListNode* left_node = cur->next;
        cur = cur->next;
        ++cur_idx;
        ListNode* prev = cur;
        while (cur_idx != right + 1) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            ++cur_idx;
        }
        left_node->next = cur;
        before_left_node->next = prev;
        return dummy->next;
    }
};

ListNode* vec2list(const vector<int>& v) {
    ListNode* head = new ListNode();
    ListNode* cur = head;
    int i = 0;
    for (;i < v.size() - 1; ++i) {
        cur->val = v[i];
        cur->next = new ListNode();
        cur = cur->next;
    }
    cur->val = v[v.size() - 1];
    return head;
}

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    // vector<int> v = {1,2,3,4,5};
    vector<int> v = {1};
    ListNode* head = s.reverseBetween(vec2list(v), 1, 1);
    while (head) {
        cout << head->val;
        head = head->next;
    }
    return 0;
}