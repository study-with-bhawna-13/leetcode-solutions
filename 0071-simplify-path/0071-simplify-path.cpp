class Solution {
public:
vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        stringstream ss(s);
        while (getline(ss, token, delimiter)) {
            if (!token.empty()) { 
                tokens.push_back(token);
            }
        }
        return tokens;
    }

    string simplifyPath(string path) {
        stack<string> s;
        for(auto &i: split(path,'/')){
            if(i == ".."){
                if (!s.empty()) s.pop();
            }
            else if(i!="."){
                s.push(i);
            }
        }
        string ans="";
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        return ans.empty() ? "/" : ans; 
    }
};