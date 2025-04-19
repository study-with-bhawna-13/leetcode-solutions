class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = min(cost[0]+cost[1],cost[1]);
        for(int i=2;i<n;i+=1){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
            cout<<dp[i]<<" ";
        }
        return min(dp[n-2],dp[n-1]);
    }
};