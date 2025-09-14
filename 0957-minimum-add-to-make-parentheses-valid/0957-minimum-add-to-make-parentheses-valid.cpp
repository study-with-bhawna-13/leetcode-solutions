class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<char> st;
        for(auto i:s){
            if(i=='(')
            {
                st.push(i);
            }else{
                if(!st.empty())
                st.pop();
                else ans+=1;
            }
        }
        return ans+st.size();
    }
};