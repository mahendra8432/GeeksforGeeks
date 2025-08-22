class Solution {
public:
    int median(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[0][cols - 1];

        // Find overall min and max
        for (int r = 1; r < rows; r++) {
            low = min(low, matrix[r][0]);
            high = max(high, matrix[r][cols - 1]);
        }

        int target = (rows * cols + 1) / 2;

        // Binary search between low and high
        while (low < high) {
            int midVal = low + (high - low) / 2;
            int count = 0;

            // Count elements <= midVal
            for (int r = 0; r < rows; r++) {
                count += upper_bound(matrix[r].begin(), matrix[r].end(), midVal) - matrix[r].begin();
            }

            if (count < target) {
                low = midVal + 1;
            } else {
                high = midVal;
            }
        }
        return high;
    }
};
