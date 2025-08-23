class Solution {
public:
    static bool fun(vector<int> &a, vector<int> &b){
        int x=(a[0]*a[0] + a[1]*a[1]);
        int y=(b[0]*b[0] + b[1]*b[1]);
        return x<y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> p(points.begin(),points.end());
        sort(p.begin(),p.end(),fun);
        p.erase(p.begin()+k,p.end());
        return p;
    }
};