class Solution {
  public:
    int fun(int n, int sum,int sum1,int sum2,vector<int>& arr,int d,vector<vector<int>>&dp){
        if(n==0){
            // try both choices for last element
            int cnt=0;
            if(sum1 - sum2 == d) cnt++;
            if((sum1+arr[0]) - (sum2 - arr[0]) == d) cnt++;
            return cnt;
        }
        if(dp[n][sum1]!=-1) return dp[n][sum1];
        int nottake=fun(n-1,sum,sum1,sum2,arr,d,dp);
        int take=0;
        take=fun(n-1,sum,sum1+arr[n],sum2-arr[n],arr,d,dp);
        return dp[n][sum1] = nottake+take;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return fun(n-1,sum,0,sum,arr,d,dp);
    }
};