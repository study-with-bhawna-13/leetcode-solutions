class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minP = prices[0];
        for(auto i:prices){
            ans=max(ans,i-minP);
            minP=min(minP,i);
        }
        return ans;
    }
};