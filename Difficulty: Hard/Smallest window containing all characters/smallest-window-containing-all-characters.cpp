class Solution {
public:
    string smallestWindow(string &s, string &p) {
        int m = s.size(), n = p.size();
        if (m < n) return "";
        int freq[256] = {0}, window[256] = {0};
        for (char c : p) freq[c]++;
        int formed = 0, required = 0;
        for (int i = 0; i < 256; i++) if (freq[i] > 0) required++;
        int l = 0, r = 0, minLen = INT_MAX, minStart = 0;
        while (r < m) {
            window[s[r]]++;
            if (freq[s[r]] > 0 && window[s[r]] == freq[s[r]]) formed++;
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }
                window[s[l]]--;
                if (freq[s[l]] > 0 && window[s[l]] < freq[s[l]]) formed--;
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};