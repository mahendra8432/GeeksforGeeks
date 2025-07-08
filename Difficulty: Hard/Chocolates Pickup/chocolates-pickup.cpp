class Solution {
  public:
    int fun(int i,int j1,int j2,vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2) maxi= max(maxi,grid[i][j1] + fun(i+1,j1+dj1,j2+dj2,grid,dp));
                else maxi= max(maxi,grid[i][j1] + grid[i][j2]+ fun(i+1,j1+dj1,j2+dj2,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
       return fun(0,0,m-1,grid,dp);
    }
};