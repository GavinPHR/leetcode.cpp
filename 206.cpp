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
 
// Iterative
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head) return head;
//         ListNode* prev = nullptr;
//         ListNode* next;
//         while (head) {
//             next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }
//         return prev;
//     }
// };

// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* sub = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return sub;
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
    vector<int> v = {1,2,3,4,5};
    ListNode* head = s.reverseList(vec2list(v));
    while (head) {
        cout << head->val;
        head = head->next;
    }
    return 0;
}