class Solution {
public:
    int maxGold(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        for (int j = cols - 2; j >= 0; --j) {
            for (int i = 0; i < rows; ++i) {
                int best = 0;
                for (int d = -1; d <= 1; ++d) {
                    int ni = i + d;
                    if (ni >= 0 && ni < rows) {
                        best = max(best, grid[ni][j + 1]);
                    }
                }
                grid[i][j] += best;
            }
        }

        int maxTotal = 0;
        for (int i = 0; i < rows; ++i) {
            maxTotal = max(maxTotal, grid[i][0]);
        }

        return maxTotal;
    }
};
