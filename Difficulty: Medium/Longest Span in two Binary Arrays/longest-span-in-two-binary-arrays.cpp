class Solution {
  public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int maxLength = 0;
        unordered_map<int, int> diffIndex;
        int prefixSum1 = 0, prefixSum2 = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum1 += arr1[i];
            prefixSum2 += arr2[i];

            int diff = prefixSum1 - prefixSum2;

            if (diff == 0) {
                maxLength = i + 1;
            } else if (diffIndex.count(diff)) {
                maxLength = max(maxLength, i - diffIndex[diff]);
            } else {
                diffIndex[diff] = i;
            }
        }

        return maxLength;
    }
};
