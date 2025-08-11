class Solution {
public:
    int maxSum(string& s) {
        int n = s.size();
        vector<int> left(n, 1), right(n, 1), rad(n);
        
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(rad[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            rad[i] = k--;
            if (i + k > r) l = i - k, r = i + k;
        }
        
        for (int i = 0; i < n; i++) {
            int len = rad[i] * 2 - 1;
            int end = i + rad[i] - 1;
            if (end < n) left[end] = max(left[end], len);
        }
        
        for (int i = n - 2; i >= 0; i--) left[i] = max(left[i], left[i + 1] - 2);
        for (int i = 1; i < n; i++) left[i] = max(left[i], left[i - 1]);
        
        for (int i = n - 1; i >= 0; i--) {
            int len = rad[i] * 2 - 1;
            int start = i - rad[i] + 1;
            if (start >= 0) right[start] = max(right[start], len);
        }
        
        for (int i = 1; i < n; i++) right[i] = max(right[i], right[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) right[i] = max(right[i], right[i + 1]);
        
        int ans = 0;
        for (int i = 0; i + 1 < n; i++) ans = max(ans, left[i] + right[i + 1]);
        return ans ;
    }
};