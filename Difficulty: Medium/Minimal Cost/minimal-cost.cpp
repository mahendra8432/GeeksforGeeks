class Solution {
  public:
  int fun(int n,vector<int>& height,vector<int>&temp,int k){
            int mini=INT_MAX;
            if(n==0) return 0;
            if(n==1) return abs(height[1]-height[0]);
            if(temp[n]!=-1) return temp[n];
            // left  = fun(n-1,height,temp) + abs(height[n]-height[n-1]);
            // right = fun(n-2,height,temp) + abs(height[n]-height[n-2]);
            for(int i=1;i<=min(k,n);i++){
                mini=min((fun(n-i,height,temp,k) + abs(height[n]-height[n-i])),mini);
            }
            return temp[n]=mini;
        }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int>temp(n,-1);
        return fun(n-1,arr,temp,k);
        
    }
};