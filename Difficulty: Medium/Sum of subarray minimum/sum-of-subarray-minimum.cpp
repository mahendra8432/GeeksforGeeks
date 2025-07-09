class Solution {
public:
    int sumSubMins(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            left[i] = stk.empty() ? i + 1 : i - stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) stk.pop();
            right[i] = stk.empty() ? n - i : stk.top() - i;
            stk.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total = (total + (long long)nums[i] * left[i] * right[i]) % MOD;
        }

        return total;
    }
};
