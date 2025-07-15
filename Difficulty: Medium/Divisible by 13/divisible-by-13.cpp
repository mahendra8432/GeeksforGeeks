class Solution {
public:
    bool divby13(string &s) {
        int r = 0;
        for (int i = 0; i < s.length(); ++i) {
            r = (r * 10 + s[i] - '0') % 13;
        }
        return !r;
    }
};