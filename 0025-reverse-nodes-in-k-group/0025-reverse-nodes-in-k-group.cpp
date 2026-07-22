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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head, *tmp = head;
        stack<ListNode*> s;
        while (node && s.size() != k) {
            s.push(node);
            node = node->next;
        }
        if (s.size() == k) {
            head->next = reverseKGroup(node, k);
            tmp = s.top();
            while (!s.empty()) {
                node = s.top();
                s.pop();
                if(!s.empty())
                node->next = s.top();
            }
        }
        return tmp;
    }
};