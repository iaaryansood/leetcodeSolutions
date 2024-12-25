class Solution {
    int helper(vector<vector<int>> &grid,vector<vector<int>> &dp,int n,int m)
    {
        if(n == 0 && m == 0)
        {
            return grid[0][0];
        }
        if(n < 0 || m < 0)
        {
            return 1e9;
        }
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        else
        {
            int left=helper(grid,dp,n,m-1);
            int up=helper(grid,dp,n-1,m);
            return dp[n][m]=min(grid[n][m] + up,grid[n][m] + left);
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0] = grid[0][0];
        return helper(grid,dp,n-1,m-1);
    }
};