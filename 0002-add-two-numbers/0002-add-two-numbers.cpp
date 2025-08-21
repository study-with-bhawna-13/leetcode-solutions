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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans = nullptr, *itr = ans;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = carry;
            if (l1 != nullptr)
                x += l1->val;
            if (l2 != nullptr)
                x += l2->val;
            carry = x / 10;
            x %= 10;
            if (itr == nullptr) {
                ans = new ListNode(x);
                itr = ans;
            } else {
                itr->next = new ListNode(x);
                itr = itr->next;
            }
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return ans;
    }
};