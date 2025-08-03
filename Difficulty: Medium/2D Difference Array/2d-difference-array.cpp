class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
        
        for (auto& q : opr) {
            int v = q[0], r1 = q[1], c1 = q[2], r2 = q[3], c2 = q[4];
            d[r1][c1] += v;
            d[r1][c2 + 1] -= v;
            d[r2 + 1][c1] -= v;
            d[r2 + 1][c2 + 1] += v;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) d[i][j] += d[i - 1][j];
                if (j) d[i][j] += d[i][j - 1];
                if (i && j) d[i][j] -= d[i - 1][j - 1];
                mat[i][j] += d[i][j];
            }
        }
        return mat;
    }
};