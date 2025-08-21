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
        ListNode *ans =nullptr, *itr = ans;
        while(l1 != nullptr && l2 != nullptr){
            int x = l1->val + l2->val + carry;
            carry = x/10;
            x%=10;
            if(itr==nullptr){
                ans=new ListNode(x);
                itr=ans;
            }else{
                itr->next = new ListNode(x);
                itr=itr->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1 != nullptr){
            int x = l1->val + carry;
            carry = x/10;
            x%=10;
            if(itr==nullptr){
                ans=new ListNode(x);
                itr=ans;
            }else{
                itr->next = new ListNode(x);
                itr=itr->next;
            }
            l1=l1->next;
        }
        while(l2 != nullptr){
            int x = l2->val + carry;
            carry = x/10;
            x%=10;
            if(itr==nullptr){
                ans=new ListNode(x);
                itr=ans;
            }else{
                itr->next = new ListNode(x);
                itr=itr->next;
            }
            l2=l2->next;
        }
        if(carry){
            itr->next = new ListNode(carry);
        }
        return ans;
    }
};