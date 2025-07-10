class Solution {
  public:
    // int fun(int n, int target,vector<int>& arr,vector<vector<int>>&dp){
    //     int take=0,nottake=0;
    //     if(n==0) {
    //          if(target==0 && arr[0]==0) return 2;
    //          if(target==0 || arr[0]==target) return 1;
    //          return 0;
    //     }
    //     if(dp[n][target]!=-1) return dp[n][target];
    //     nottake= fun(n-1,target,arr,dp);
    //     if(target>=arr[n]) take=  fun(n-1,target-arr[n],arr,dp);
    //     return dp[n][target]= (nottake + take);
    // }
    //Method 2:- Tabulation.
    int mod=1e8;
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int take=0,nottake=0;
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
         if (arr[0] == 0) dp[0][0] = 2;  // include or exclude 0
         else dp[0][0] = 1;  // only exclude
        // Base case: sum = arr[0]
        if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=target;tar++){
                nottake=0,take=0;
                nottake= dp[i-1][tar];
                if(tar>=arr[i]) take=  dp[i-1][tar-arr[i]];
                dp[i][tar]= (nottake + take);
            }
        }
        return (dp[n-1][target])% mod;
    }
};