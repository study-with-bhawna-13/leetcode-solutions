class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        stack<int> open;
        set<int> remove;
        for(int i=0;i<s.size();i+=1){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == ')'){
                if(!open.empty()){
                    open.pop();
                }else{
                    remove.insert(i);
                }
            }
        }
        while(!open.empty()){
            remove.insert(open.top());
            open.pop();
        }
        for(int i=0;i<s.size();i+=1){
            if(remove.find(i)==remove.end())
            ans+=s[i];
        }
        return ans;
    }
};