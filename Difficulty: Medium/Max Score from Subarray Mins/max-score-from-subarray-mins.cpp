class Solution {
public:
    int maxSum(vector<int> &arr) {
        int maxSumPair = 0;
        int n = arr.size();

        for (int i = 1; i < n; ++i) {
            int currentSum = arr[i] + arr[i - 1];
            maxSumPair = max(maxSumPair, currentSum);
        }

        return maxSumPair;
    }
};
