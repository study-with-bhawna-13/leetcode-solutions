#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> diagonals;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diagonals[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> result;
        for (auto &p : diagonals) {
            for (int k = p.second.size() - 1; k >= 0; k--) {
                result.push_back(p.second[k]);
            }
        }
        return result;
    }
};
