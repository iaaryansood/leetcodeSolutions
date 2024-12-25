class Solution {
public:
    int helper(vector<vector<int>> &triangle,vector<vector<int>> &dp,int i,int j,int n,int m)
    {
        if(i == n && j <= m)
        {
            return dp[i][j]=triangle[i][j];
        }
        else if(i >=n || j >= m)
        {
            return 1e9;
        }
        else if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        else
        {
            return dp[i][j]=min(triangle[i][j] + helper(triangle,dp,i+1,j,n,m),triangle[i][j] + helper(triangle,dp,i+1,j+1,n,m));
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(triangle,dp,0,0,n-1,m-1);
    }
};