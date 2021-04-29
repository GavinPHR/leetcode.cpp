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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
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
    vector<int> a = {1,2,3,4,5};
    ListNode* head = s.getKthFromEnd(vec2list(a), 2);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
