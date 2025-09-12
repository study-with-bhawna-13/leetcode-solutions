/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* first) {
        map<Node*, Node*> m;
        Node *ans = nullptr,*head= first;
        m[nullptr] = nullptr;
        while(head!=nullptr){
            Node *tmp = new Node(head->val);
            m[head] = tmp;
            head=head->next;
        }
        head=first;
        while(head!=nullptr){
            m[head]->next=m[head->next];
            m[head]->random = m[head->random];
            head=head->next;
        }
        ans = m[first];
        return ans;
    }
};