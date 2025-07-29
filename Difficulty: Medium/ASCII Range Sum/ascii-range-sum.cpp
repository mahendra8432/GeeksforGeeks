class Solution {
public:
    vector<int> asciirange(string& s) {
        vector<int> result;
        int n = s.size();
        for (int i = 0; i < 26; i++) {
            int first = -1, last = -1;
            for (int j = 0; j < n; j++) {
                if (s[j] - 'a' == i) {
                    if (first == -1) first = j;
                    last = j;
                }
            }
            if (first != -1 && last > first) {
                int sum = 0;
                for (int k = first + 1; k < last; k++) sum += s[k];
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};