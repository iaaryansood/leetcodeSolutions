class Solution {
public:
    int helper(vector<vector<int>> &matrix,vector<vector<int>> &dp,int n,int i,int j)
    {
        if(i == n - 1 && j >= 0 && j <= n-1)
        {
            return dp[i][j]=matrix[i][j];
        }
        if(i < 0 || j < 0 || i >=n || j >= n)
        {
            return 1e9;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        else
        {
            int ans=INT_MAX;
            vector<int> dx={-1,0,1};
            for(int k=0;k<dx.size();k++)
            {
                int new_j=j+dx[k];
                ans=min(ans,matrix[i][j] + helper(matrix,dp,n,i+1,new_j));
            }
            return dp[i][j]=ans;
        }
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        // for(int i=0;i<n;i++)
        // {
        //     ans=min(ans,helper(matrix,dp,n,0,i));
        // }
        vector<int> dx={-1,0,1};
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i == n - 1)
                {
                    dp[i][j] = matrix[i][j];
                }
                else
                {
                    for(int k=0;k<dx.size();k++)
                    {
                        int new_j=j + dx[k];
                        if(new_j >= 0 && new_j < n)
                        {
                            dp[i][j] = min(dp[i][j],matrix[i][j] + dp[i+1][new_j]);
                        }
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};