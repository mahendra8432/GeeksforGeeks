class Solution {
  public:
    int fun(int n,int target, vector<int>& arr,vector<vector<int>>&dp){
        if(n==0){
            if(target==0 && arr[0]==0) return 2;
            if(target ==0 || target==arr[0]) return 1;
            return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int nottake=fun(n-1,target,arr,dp);
        int take=0;
        if(target>=arr[n]) take=fun(n-1,target-arr[n],arr,dp);
        return dp[n][target] =take+nottake;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int sum=0;
        for(auto i:arr) sum+=i;
        int target=(d+sum)/2;
        if((d+sum)%2!=0) return 0;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return fun(n-1,target,arr,dp);
        
    }
};