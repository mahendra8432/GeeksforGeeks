//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int start, int end) {
        int n = end - start + 1;
        if (n == 1) return arr[start];
        
        vector<int> dp(n);
        dp[0] = arr[start];
        dp[1] = max(arr[start], arr[start + 1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], arr[start + i] + dp[i - 2]);
        }
        
        return dp[n - 1];
    }

    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        
        int maxMoneyCase1 = solve(arr, 0, n - 2);
        int maxMoneyCase2 = solve(arr, 1, n - 1);
        
        return max(maxMoneyCase1, maxMoneyCase2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends