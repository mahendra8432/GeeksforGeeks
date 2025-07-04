class Solution {
  public:
    int fun(int n,vector<int>& height,vector<int>&temp){
        int left=0,right=0;
        if(n==0) return 0;
        if(n==1) return abs(height[1]-height[0]);
        if(temp[n]!=-1) return temp[n];
        left  = fun(n-1,height,temp) + abs(height[n]-height[n-1]);
        right = fun(n-2,height,temp) + abs(height[n]-height[n-2]);
        temp[n]=min(left,right);
        return min(left,right);
    }
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>temp(n,-1);
        return fun(n-1,height,temp);
    }
};