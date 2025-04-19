class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        dp[0][0] = triangle[0][0];
        for(int i=1;i<n;i+=1){
            for(int j=0;j<=i;j+=1){
                if(j>0){
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }else
                dp[i][j] = triangle[i][j]+dp[i-1][j];
            }
        }
        int ans=dp[n-1][n-1];
        for(int i=n-1;i>=0;i-=1){
            ans=min(dp[n-1][i],ans);
        }
        return ans;
    }
};