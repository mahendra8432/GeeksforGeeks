class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0, sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            sum += arr[i] <= k ? -1 : 1;
            if (sum > 0) ans = i + 1;
            else if (mp.count(sum - 1)) ans = max(ans, i - mp[sum - 1]);
            if (!mp.count(sum)) mp[sum] = i;
        }
        return ans;
    }
};