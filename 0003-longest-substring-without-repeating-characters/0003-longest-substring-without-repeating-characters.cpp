class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int ans = 0, left = -1;
        for (int i = 0; i < s.size(); i += 1) {
            if (m.find(s[i])!=m.end() && left < m[s[i]])
                left = m[s[i]];
            m[s[i]] = i;
            ans = max(ans, i - left);
        }
        return ans;
    }
};