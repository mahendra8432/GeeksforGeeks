class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;   // frequency map
        set<pair<int,int>> bst;        // { -freq, value }

        // Initialize first window
        for (int i = 0; i < k; i++) {
            int x = arr[i];
            if (freq[x] > 0) {
                bst.erase({-freq[x], x});
            }
            freq[x]++;
            bst.insert({-freq[x], x});
        }

        long long sum = 0;
        sum += bst.begin()->second;  // mode of first window

        // Slide the window
        for (int i = k; i < n; i++) {
            int out = arr[i-k];
            int in = arr[i];

            // Remove outgoing element
            bst.erase({-freq[out], out});
            freq[out]--;
            if (freq[out] > 0) bst.insert({-freq[out], out});

            // Add incoming element
            if (freq[in] > 0) bst.erase({-freq[in], in});
            freq[in]++;
            bst.insert({-freq[in], in});

            // Add current mode
            sum += bst.begin()->second;
        }

        return (int)sum;
    }
};
