class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for (int i : nums) {
            m[i] += i;
        }
        vector<pair<int, int>> values(m.begin(), m.end());
        int n = values.size();
        if (n == 0) return 0;
        if (n == 1) return values[0].second;
        vector<int> dp(n);
        dp[0] = values[0].second;
        if (values[1].first == values[0].first + 1) {
            dp[1] = max(values[0].second, values[1].second);
        } else {
            dp[1] = values[0].second + values[1].second;
        }
        for (int i = 2; i < n; ++i) {
            if (values[i].first == values[i - 1].first + 1) {
                dp[i] = max(dp[i - 1], dp[i - 2] + values[i].second);
            } else {
                dp[i] = dp[i - 1] + values[i].second;
            }
        }
        return dp[n - 1];
    }
};
