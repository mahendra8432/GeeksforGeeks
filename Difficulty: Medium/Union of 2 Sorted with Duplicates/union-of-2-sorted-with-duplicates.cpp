class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        int m=a.size(),n=b.size();
        vector<int>ans;
        int i=0,j=0;
       while(i<m && j<n){
           if(a[i]<=b[j]) {
               ans.push_back(a[i]);i++;
           }
          else if(a[i]>b[j]) {
               ans.push_back(b[j]);j++;
           }
           
       }
        if(j==n){
            while(i<m) {
                ans.push_back(a[i]); i++;
            }
        }
        if(i==m){
            while(j<n) {
                ans.push_back(b[j]); j++;
            }
        }
       
       // removing duplicates now
        i=0,j=1;
        for(;j<ans.size();j++){
            if(ans[j]!=ans[i]){
                i++;
                ans[i]=ans[j];
            }
        }
        ans.erase(ans.begin() + i + 1, ans.end());
         return ans;
        // return vector with correct order of elements
    }
};