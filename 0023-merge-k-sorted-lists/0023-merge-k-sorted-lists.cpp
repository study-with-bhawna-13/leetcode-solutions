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
    static bool comp(ListNode* a, ListNode* b) { return a->val > b->val; }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
                       bool (*)(ListNode*, ListNode*)>
            pq(comp);
        for (auto i : lists) {
            if (i)
                pq.push(i);
        }
        ListNode *ans = nullptr, *next = nullptr;
        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();
            if (tmp->next != nullptr) {
                pq.push(tmp->next);
            }
            if (!ans) {
                ans = tmp;
                next = tmp;
            } else {
                next->next = tmp;
                next = next->next;
            }
        }
        return ans;
    }
};