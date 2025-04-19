class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1-grid[0][0];
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (grid[i][j] != 1) {
                    if (i > 0 && grid[i - 1][j] != 1)
                        dp[i][j] += dp[i - 1][j];
                    if (j > 0 && grid[i][j - 1] != 1)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};