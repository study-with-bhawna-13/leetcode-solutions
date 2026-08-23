class Solution {
public:
    int trap(vector<int>& height) {
        int ans =0,n=height.size(),m=0;
        vector<int> right(n);
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i+1]);
        }
        for(int i=0;i<n;i+=1){
            cout<<m<<" "<<right[i]<<"\n";
            ans+=max(0,min(m,right[i])-height[i]);
            m=max(m,height[i]);
        }
        return ans;
    }
};