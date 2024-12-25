class Solution {
public:
    int helper(vector<vector<int>> &triangle,vector<vector<int>> &dp,int i,int j,int n)
    {
        if(i == n)
        {
            dp[n][j]=triangle[n][j];
            return dp[n][j];
        }
        else if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        else
        {
            int bottom=triangle[i][j] + helper(triangle,dp,i+1,j,n);
            int bottomRight=triangle[i][j] + helper(triangle,dp,i+1,j+1,n);
            dp[i][j]=min(bottom,bottomRight);
            return dp[i][j];
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(triangle,dp,0,0,n-1);
    }
};