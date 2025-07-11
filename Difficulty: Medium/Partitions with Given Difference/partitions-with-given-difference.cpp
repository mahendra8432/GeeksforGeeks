class Solution {
  public:
  // Method 2:-Tabulation.
   int mod=1e8;
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int sum=0;
        for(auto i:arr) sum+=i;
        int target=(d+sum)/2;
        if((d+sum)%2!=0) return 0;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        int take=0,nottake=0;
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