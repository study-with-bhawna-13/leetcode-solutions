class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        int ans=(n-1)*min(arr[left],arr[right]);
        while(left<right){
            if(arr[left]>arr[right])
            right--;
            else
            left++;
            ans=max(ans,(right-left)*min(arr[left],arr[right]));
        }
    return ans;
    }

};