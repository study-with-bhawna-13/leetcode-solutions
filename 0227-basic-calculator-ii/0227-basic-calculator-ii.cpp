class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        char op = '+';
        stack<long long> st;
        for (int i = 0; i < s.size(); i += 1) {
            if (s[i] <= '9' && s[i] >= '0') {
                num *= 10;
                num += s[i] - '0';
            }
            if ((i == s.size() - 1) ||
                (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) {
                if (op == '+')
                    st.push(num);
                else if (op == '-')
                    st.push(-num);
                else if (op == '*') {
                    long long x = st.top();
                    st.pop();
                    st.push(x * num);
                } else if (op == '/') {
                    long long x = st.top();
                    st.pop();
                    st.push(x / num);
                }
                num = 0;
                op = s[i];
            }
        }
        long long ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};