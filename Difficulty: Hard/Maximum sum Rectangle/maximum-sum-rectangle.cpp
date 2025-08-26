class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int l = 0; l < n; l++) {
            vector<int> temp(m, 0);
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) temp[i] += mat[i][r];
                int sum = 0, maxSum = temp[0];
                for (int x : temp) {
                    sum = max(x, sum + x);
                    maxSum = max(maxSum, sum);
                }
                res = max(res, maxSum);
            }
        }
        return res;
    }
};