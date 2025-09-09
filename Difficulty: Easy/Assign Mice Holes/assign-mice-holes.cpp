class Solution {
public:
    int assignHole(vector<int>& m, vector<int>& h) {
        sort(m.begin(), m.end());
        sort(h.begin(), h.end());
        int r = 0;
        for (int i = 0; i < m.size(); ++i) 
            r = max(r, abs(m[i] - h[i]));
        return r;
    }
};