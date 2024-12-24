class Solution {
public:
    int helper(vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp,int n,int m)
    {
        if(n == 0 && m == 0)
        {
            if(obstacleGrid[0][0] == 0)
            {
                return 1;
            }
            if(obstacleGrid[0][0] == 1)
            {
                return 0;
            }
        }
        if(n < 0 || m < 0)
        {
            return 0;
        }
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        else
        {
            int up=0,left=0;
            if(n-1 >= 0 && obstacleGrid[n-1][m] == 0)
            {
                up = helper(obstacleGrid,dp,n-1,m);
            }
            if(m - 1 >= 0 && obstacleGrid[n][m-1] == 0)
            {
                left = helper(obstacleGrid,dp,n,m-1);
            }
            return dp[n][m] = up+left;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(obstacleGrid,dp,n-1,m-1);
    }
};