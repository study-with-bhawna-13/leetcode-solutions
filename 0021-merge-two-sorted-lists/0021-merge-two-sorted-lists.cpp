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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *node, *head, *ans;
        node = head = ans = NULL;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val > list2->val) {
                node = list2;
                list2 = list2->next;
            } else {
                node = list1;
                list1 = list1->next;
            }
            if (head == NULL) {
                head = ans = node;
            } else {
                head->next = node;
                head = head->next;
            }
        }
        if (list1 != NULL)
            if (head)
                head->next = list1;
            else
                ans = list1;
        if (list2 != NULL)
            if (head)
                head->next = list2;
            else
                ans = list2;

        return ans;
    }
};