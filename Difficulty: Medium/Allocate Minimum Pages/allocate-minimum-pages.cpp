class Solution {
public:
    int findPages(vector<int>& arr, int k) {
        if (k > (int)arr.size()) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 1, sum = 0;

            for (int val : arr) {
                if (sum + val > mid) {
                    count++;
                    sum = val;
                } else {
                    sum += val;
                }
            }

            if (count <= k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
