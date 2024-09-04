class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    if(grid[i][j] == 1)
                    {
                        visited[i][j]=1;
                        q.push(pair<int,int>(i,j));
                    }
                }
            }
        }

        vector<pair<int,int>> directions={{-1,0},{0,-1},{1,0},{0,1}};

        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();

            int row=p.first;
            int col=p.second;

            for(int i=0;i<4;i++)
            {
                int delrow=row + directions[i].first;
                int delcol=col + directions[i].second;

                if(delrow >=0 && delcol  >=0 && delrow < n && delcol < m)
                {
                    if(grid[delrow][delcol] == 1 && !visited[delrow][delcol])
                    {
                        q.push(pair<int,int>(delrow,delcol));
                        visited[delrow][delcol]=1;
                    }
                }
            }

        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    count++;
                }
            }
        }

        return count;

    }
};