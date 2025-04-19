class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (i == 0)
                    dp[i][j] = matrix[i][j];
                else {
                    dp[i][j] = dp[i - 1][j];
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    if (j < n - 1)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                    dp[i][j] += matrix[i][j];
                }
            }
        }
        int ans = dp[n - 1][0];
        for (int i = 1; i < n; i += 1)
            ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};