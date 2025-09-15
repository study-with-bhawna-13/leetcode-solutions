#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return {};
        int m = mat[0].size();
        vector<int> result;
        for (int d = 0; d <= n + m - 2; d++) {
            if (d % 2 == 0) {
                int i = min(d, n - 1);
                int j = d - i;
                while (i >= 0 && j < m) {
                    result.push_back(mat[i][j]);
                    i--; j++;
                }
            } else {
                int j = min(d, m - 1);
                int i = d - j;
                while (i < n && j >= 0) {
                    result.push_back(mat[i][j]);
                    i++; j--;
                }
            }
        }
        return result;
    }
};
