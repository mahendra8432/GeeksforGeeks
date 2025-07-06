class Solution {
public:
    vector<int> topKSumPairs(vector<int>& A, vector<int>& B, int k) {
        int n = A.size();
        sort(A.begin(), A.end(), greater<>());
        sort(B.begin(), B.end(), greater<>());

        priority_queue<tuple<int, int, int>> maxHeap;
        unordered_set<long long> visited;
        maxHeap.emplace(A[0] + B[0], 0, 0);
        visited.insert(0);

        vector<int> result;

        while (result.size() < k) {
            int currentSum = get<0>(maxHeap.top());
            int i = get<1>(maxHeap.top());
            int j = get<2>(maxHeap.top());
            maxHeap.pop();
            result.push_back(currentSum);

            if (i + 1 < n && visited.insert((long long)(i + 1) * n + j).second) {
                maxHeap.emplace(A[i + 1] + B[j], i + 1, j);
            }
            if (j + 1 < n && visited.insert((long long)i * n + j + 1).second) {
                maxHeap.emplace(A[i] + B[j + 1], i, j + 1);
            }
        }

        return result;
    }
};
