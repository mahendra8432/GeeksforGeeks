class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        if ((long long)k * m > arr.size()) return -1;
        int l = *min_element(arr.begin(), arr.end());
        int r = *max_element(arr.begin(), arr.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            int flowers = 0, bouquets = 0;
            for (int bloom : arr) {
                if (bloom <= mid) {
                    if (++flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else flowers = 0;
            }
            if (bouquets >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};