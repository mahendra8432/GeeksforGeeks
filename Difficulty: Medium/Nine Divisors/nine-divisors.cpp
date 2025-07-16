class Solution {
public:
    int countNumbers(int n) {
        int count = 0, limit = sqrt(n);
        vector<int> spf(limit + 1);
        iota(spf.begin(), spf.end(), 0);

        for (int i = 2; i * i <= limit; ++i)
            if (spf[i] == i)
                for (int j = i * i; j <= limit; j += i)
                    if (spf[j] == j) spf[j] = i;

        for (int i = 2; i <= limit; ++i) {
            int p = spf[i];
            int q = spf[i / p];
            if (p * q == i && p != q && q != 1) ++count;
            else if (spf[i] == i && pow(i, 8) <= n) ++count;
        }

        return count;
    }
};
