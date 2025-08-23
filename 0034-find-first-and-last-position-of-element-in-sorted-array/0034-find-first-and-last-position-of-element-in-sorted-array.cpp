class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        auto lb = lower_bound(nums.begin(), nums.end(), target); // first >=
        auto ub = upper_bound(nums.begin(), nums.end(), target); // first >
        if (lb == nums.end() || *lb != target) {
            return ans;
        }
        ans[0] = lb - nums.begin();
        ans[1] = ub - nums.begin() - 1;
        return ans;
    }
};