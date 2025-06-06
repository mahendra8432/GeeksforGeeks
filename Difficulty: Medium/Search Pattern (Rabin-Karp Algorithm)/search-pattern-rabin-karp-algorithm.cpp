class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int d = 256;
        int q = 101;
        int M = pat.length();
        int N = txt.length();
        int p = 0, t = 0, h = 1;
        vector<int> ans;

        for (int i = 0; i < M - 1; i++)
            h = (h * d) % q;

        for (int i = 0; i < M; i++) {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }

        for (int i = 0; i <= N - M; i++) {
            if (p == t) {
                bool match = true;
                for (int j = 0; j < M; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    ans.push_back(i + 1); // 1-based indexing
            }

            if (i < N - M) {
                t = (d * (t - txt[i] * h) + txt[i + M]) % q;
                if (t < 0)
                    t += q;
            }
        }

        return ans;
    }
};
