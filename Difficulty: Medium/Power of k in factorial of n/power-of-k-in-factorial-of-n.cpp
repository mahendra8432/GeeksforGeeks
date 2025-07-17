class Solution {
public:
    int maxKPower(int n, int k) {
        int res = INT_MAX;
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                int cnt = 0;
                while (k % i == 0) k /= i, cnt++;
                int fact = 0;
                for (int p = i; p <= n; p *= i) fact += n / p;
                res = min(res, fact / cnt);
            }
        }
        if (k > 1) {
            int fact = 0;
            for (int p = k; p <= n; p *= k) fact += n / p;
            res = min(res, fact);
        }
        return res == INT_MAX ? 0 : res;
    }
};