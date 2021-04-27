#include <iostream>
#include <vector>

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
    void reorderList(ListNode* head) {
        if (!head->next) return;
        // reverse right half
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = slow->next, *cur = prev->next; 
        while (cur) {
            prev->next = cur->next;
            cur->next = slow->next;
            slow->next = cur;
            cur = prev->next;
        }
        ListNode *left = head;
        prev = slow, cur = prev->next;
        while (cur && left) {
            prev->next = cur->next;
            cur->next = left->next;
            left->next = cur;
            left = cur->next;
            cur = prev->next;
        }
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

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> a = {1,2,3,4};
    ListNode* head = vec2list(a);
    s.reorderList(head);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    a = {1,2,3,4,5};
    head = vec2list(a);
    s.reorderList(head);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
