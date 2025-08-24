class Solution {
public:
    string customSortString(string order, string st) {
        vector<char> s(st.begin(), st.end());
        sort(s.begin(), s.end(), [&](char& a, char& b) {
            int x = order.find(a);
            if (x == string::npos)
                x = order.size();
            int y = order.find(b);
            if (y == string::npos)
                y = order.size();
            return x < y;
        });
        string ans = "";
        for (auto i : s) {
            ans += i;
        }
        return ans;
    }
};