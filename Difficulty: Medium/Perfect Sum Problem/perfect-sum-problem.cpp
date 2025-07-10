class Solution {
  public:
    int fun(int n, int target,vector<int>& arr,vector<vector<int>>&dp){
        int take=0,nottake=0;
        if(n==0) {
             if(target==0 && arr[0]==0) return 2;
             if(target==0 || arr[0]==target) return 1;
             return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        nottake= fun(n-1,target,arr,dp);
        if(target>=arr[n]) take=  fun(n-1,target-arr[n],arr,dp);
        return dp[n][target]= (nottake + take);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return fun(n-1,target,arr,dp);
    }
};