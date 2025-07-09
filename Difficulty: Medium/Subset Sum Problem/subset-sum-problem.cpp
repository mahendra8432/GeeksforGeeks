class Solution {
  public:
    bool fun(int n,int target,vector<int>& arr,vector<vector<int>> &dp){
        if(target==0) return true;
        if(n==0) return (target==arr[0]);
        if(dp[n][target]!=-1) return 0;
        bool nottake=fun(n-1,target,arr,dp);
        bool take= false;
        if(target>=arr[n])  take=fun(n-1,target-arr[n],arr,dp);
        return dp[n][target]= take||nottake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return fun(n-1,sum,arr,dp);
    }
};