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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev;
        ListNode* head = l1;
        int a, b;
        while (l1 || l2) {
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            int val = a + b + carry;
            if (l1) {
                l1->val = val % 10;
                prev = l1;
                l1 = l1->next;
            } else {
                prev->next = new ListNode(val % 10);
                prev = prev->next;
            }
            if (l2){
                l2 = l2->next;
            }
            carry = val / 10;
        }
        if (carry) {
            prev->next = new ListNode(1);
        }
        return head;
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
    vector<int> a = {9,9,9,9,9,9,9};
    vector<int> b = {9,9,9,9};
    for (auto i: a) {
        cout << i;
    }
    ListNode* head = s.addTwoNumbers(vec2list(a), vec2list(b));
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}