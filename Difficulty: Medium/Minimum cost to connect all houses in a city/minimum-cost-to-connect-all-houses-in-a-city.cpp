//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        // Min-heap: {cost, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        minHeap.push({0, 0}); // Start from the first house
        int totalCost = 0;
        int edgesUsed = 0;

        while (edgesUsed < n) {
            pair<int, int> current = minHeap.top();
            minHeap.pop();
            int cost = current.first;
            int u = current.second;

            if (visited[u]) continue;

            visited[u] = true;
            totalCost += cost;
            edgesUsed++;

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    minHeap.push({dist, v});
                }
            }
        }

        return totalCost;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends