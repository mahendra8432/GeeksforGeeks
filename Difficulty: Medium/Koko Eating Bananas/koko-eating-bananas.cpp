class Solution {
public:
    int kokoEat(vector<int>& bananas, int k) {
        int low = 1;
        int high = *max_element(bananas.begin(), bananas.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            int totalHours = 0;

            for (int pile : bananas) {
                totalHours += (pile + mid - 1) / mid;  // Same as ceil(pile / mid)
            }

            if (totalHours <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
