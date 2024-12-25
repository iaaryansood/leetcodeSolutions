class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        // cout<<n<<" "<<m;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
        {
            // cout<<"obstacle"<<endl;
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[1][1] = 1;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(i == 1 && j == 1)
                {
                    dp[1][1] = 1;
                }
                else if(obstacleGrid[i-1][j-1] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        // cout<<endl;
        // for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<m+1;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};