class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i == n-1)
                {
                    dp[i][j] = triangle[i][j];
                }
                else
                {
                    dp[i][j] = min(triangle[i][j] + dp[i+1][j],triangle[i][j] + dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};