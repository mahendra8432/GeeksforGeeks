class Solution {
public:
  //potd july-4
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size(), res = 0, left = 0;
        unordered_map<int, int> freq;
        for (int right = 0; right < n; right++) {
            if (freq[arr[right]]++ == 0) k--;
            while (k < 0) {
                if (--freq[arr[left]] == 0) k++;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};