class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return nums[n-1];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i=2;i<n;i+=1){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return max(dp[n-1], dp[n-2]);

    }
};