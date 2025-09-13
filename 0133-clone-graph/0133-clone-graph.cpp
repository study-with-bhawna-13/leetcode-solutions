/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    static void dfs(Node* node, map<Node*, Node *> &m, map<Node*,bool> &vis){
        if(node == nullptr) return;
        if(vis[node]) return;
        m[node] = new Node(node->val);
        vis[node] = true;
        for(auto i:node->neighbors){
            dfs(i,m,vis);
        }
    }
    void mapNeighbors(map<Node*, Node*> &m){
        for(auto i: m){
            for(auto j: i.first->neighbors){
                i.second->neighbors.push_back(m[j]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        map<Node *, Node *> m;
        map<Node*, bool> vis;
        dfs(node,m,vis);
        mapNeighbors(m);
        return m[node];
    }
};