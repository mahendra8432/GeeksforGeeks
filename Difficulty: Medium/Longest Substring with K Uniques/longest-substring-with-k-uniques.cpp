class Solution {
public:
    int longestKSubstr(string &str, int k) {
        int len = str.length();
        int left = 0, right = 0;
        int uniqueCount = 0;
        int maxLength = -1;
        vector<int> freq(26, 0);

        while (right < len) {
            int index = str[right] - 'a';
            if (freq[index] == 0) uniqueCount++;
            freq[index]++;

            while (uniqueCount > k) {
                int leftIndex = str[left] - 'a';
                freq[leftIndex]--;
                if (freq[leftIndex] == 0) uniqueCount--;
                left++;
            }

            if (uniqueCount == k) {
                maxLength = max(maxLength, right - left + 1);
            }

            right++;
        }

        return maxLength;
    }
};
