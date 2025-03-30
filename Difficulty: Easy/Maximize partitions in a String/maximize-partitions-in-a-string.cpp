//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char, int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        int next = 0;
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            next = max(mp[s[i]], next);
            if(next == i)   ans++;
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends