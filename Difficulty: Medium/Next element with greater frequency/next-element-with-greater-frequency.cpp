class Solution {
public:
    vector<int> findGreater(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int val : nums) freq[val]++;

        vector<int> result(nums.size(), -1);
        stack<int> indices;

        for (int i = 0; i < nums.size(); ++i) {
            while (!indices.empty() && freq[nums[i]] > freq[nums[indices.top()]]) {
                result[indices.top()] = nums[i];
                indices.pop();
            }
            indices.push(i);
        }

        return result;
    }
};
