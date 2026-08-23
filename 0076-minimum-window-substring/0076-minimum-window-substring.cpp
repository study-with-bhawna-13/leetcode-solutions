class Solution {
public:
    int ind(char c) {
        if (c >= 'a' && c <= 'z')
            return c - 'a';
        return 26 + c - 'A';
    }
    bool check(vector<int>& v) {
        int x = 0;
        for (int i = 0; i < 52; i += 1) {
            if (v[i] <= 0)
                x++;
        }
        return x == 52;
    }
    string minWindow(string s, string t) {
        vector<int> v(52);
        for (auto i : t) {
            v[ind(i)] += 1;
        }
        int min_len = INT_MAX;
        int start_idx = -1;
        int l = 0;
        for (int r = 0; r < s.size(); r += 1) {
            v[ind(s[r])] -= 1;
            while (check(v)) {
                if (r - l + 1 < min_len) {
                    start_idx = l;
                    min_len = r - l + 1;
                }
                v[ind(s[l++])] += 1;
            }
        }
        return start_idx == -1 ? "" : s.substr(start_idx, min_len);
    }
};