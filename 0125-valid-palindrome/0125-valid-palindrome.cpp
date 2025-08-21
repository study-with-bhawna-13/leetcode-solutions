class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;
        for(auto i:s){
            if(i>='A' && i<='Z')
            v.push_back(i-'A'+'a');
            if((i>='a' && i<='z') || (i<='9' &&i>='0'))
            v.push_back(i);
        }
        int i=0;
        while(i<v.size()/2){
            if(v[i]!=v[v.size()-1-i]) return false;
            i+=1;
        }
        return true;
    }
};