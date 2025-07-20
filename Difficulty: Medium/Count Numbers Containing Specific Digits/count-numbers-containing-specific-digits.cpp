class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        int mask = 0, nonZeroMask = 0;
        for (int d : arr) {
            mask |= (1 << d);
            if (d) nonZeroMask |= (1 << d);
        }
        int forbidden = __builtin_popcount(~mask & 1023);
        int nonZeroForbidden = __builtin_popcount(~nonZeroMask & 1022);
        
        int total = 9, pow = 1;
        for (int i = 1; i < n; i++) {
            pow *= 10;
            total *= 10;
        }
        
        int invalid = n == 1 ? nonZeroForbidden : nonZeroForbidden;
        for (int i = 1; i < n; i++) invalid *= forbidden;
        
        return total - invalid;
    }
};