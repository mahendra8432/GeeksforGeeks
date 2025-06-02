class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dp(cols, 0);

        // Initialize the first cell
        dp[0] = (grid[0][0] == 0) ? 1 : 0;

        // Traverse the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    dp[j] = 0;  // Blocked cell
                } else if (j > 0) {
                    dp[j] += dp[j - 1];  // Add paths from the left
                }
                // No need to do anything for j == 0 (first column)
            }
        }

        return dp[cols - 1];
    }
};
