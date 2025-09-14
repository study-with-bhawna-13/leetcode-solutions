class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0, ans = 0, sign = 1;
        for (auto i : s) {
            if (i >= '0' && i <= '9') {
                num *= 10;
                num += (i - '0');
            } else if (i == '(') {
                st.push(ans);
                st.push(sign);
                num = ans = 0;
                sign = 1;
            } else if (i == ')') {
                int prevSign = st.top();
                st.pop();
                int prevNum = st.top();
                st.pop();
                ans += sign * num;
                ans = prevNum + prevSign * ans;
                num = 0;
                sign = 1;
            } else if (i == '+' || i == '-') {
                ans += sign * num;
                sign = (i == '+') ? 1 : -1;
                num = 0;
            }
        }
        ans += num*sign;
        return ans;
    }
};