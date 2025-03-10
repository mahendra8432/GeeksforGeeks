//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int countWaysRec(int n, vector<int>& memo) {
  
      // Base cases
    if (n == 0 || n == 1)
        return 1;

      // if the result for this subproblem is 
      // already computed then return it
    if (memo[n] != -1) 
        return memo[n];
    
    return memo[n] = countWaysRec(n - 1, memo) +
                           countWaysRec(n - 2, memo);
}

        int countWays(int n) {
          
              // Memoization array to store the results
              vector<int> memo(n + 1, -1);
              return countWaysRec(n, memo);
        }

};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends