class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(i == 1 && j == 1)
                {
                    dp[1][1] = grid[0][0];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j] + grid[i-1][j-1],dp[i][j-1] + grid[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};