//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int maxi=-1,max2=-1;
        if(n==2) {
            if(arr[0]==arr[1]) return -1;
            else if(arr[0]>arr[1]) return arr[1];
            else return arr[0];
        }
        for(int i=0;i<n;i++) {
           if(arr[i]>maxi) maxi=arr[i];
        }
         for(int i=0;i<n;i++) {
           if(arr[i]>max2 && arr[i]!=maxi) max2=arr[i];
        }
        return max2;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends