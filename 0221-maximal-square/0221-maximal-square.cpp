class Solution {
public:
    bool check(int i, int j, int m, int n, vector<vector<int>>& dp) {
        return ((i < m) && (j < n)) ? dp[i][j] : 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] != '0') {
                    dp[i][j] = 1 + min(min(dp[i + 1][j], dp[i][j + 1]),
                                       dp[i + 1][j + 1]);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};