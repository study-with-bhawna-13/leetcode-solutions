class Solution {
public:
    static bool fun(vector<int> &a, vector<int> &b){
        return a[0]==b[0]? a[1]<b[1]:a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),fun);
        int i=0;
        while(i<intervals.size()-1){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i][1] = max(intervals[i+1][1],intervals[i][1]);
                intervals.erase(intervals.begin()+i+1);
            }else{
                i+=1;
            }
        }
        return intervals;
    }
};