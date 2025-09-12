
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        sort(arr.begin(), arr.end());
        if (k == 0) {
            return arr[n-1] - arr[0];
        }
        
        int idx = 0;
        while (idx < n && arr[idx] < k) {
            idx++;
        }
        
        if (idx == n) {
            return arr[n-1] - arr[0];
        }
        
        int ans = arr[n-1] - arr[0];
        int start = max(0, idx - 1);
        for (int i = start; i < n-1; i++) {
            int low = min(arr[0] + k, arr[i+1] - k);
            int high = max(arr[i] + k, arr[n-1] - k);
            ans = min(ans, high - low);
        }
        return ans;
    }
};