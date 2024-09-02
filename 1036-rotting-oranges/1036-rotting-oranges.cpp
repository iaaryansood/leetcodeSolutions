class Solution {
private:
    int bfs(int n,int m,vector<vector<int>> &visited,queue<pair<int,pair<int,int>>> &q,vector<vector<int>> &grid)
    {
        int depth=0;
        while(!q.empty())
        {
                pair<int,pair<int,int>> temp=q.front();

                depth=temp.first;
                int row=temp.second.first;
                int col=temp.second.second;

                q.pop();

                if(row - 1 >= 0 && !visited[row-1][col] && grid[row-1][col] == 1)
                {
                    grid[row-1][col]=2;
                    visited[row-1][col]=1;
                    q.push(pair<int,pair<int,int>>(depth+1,pair<int,int>(row-1,col)));
                }

                if(col - 1 >= 0 && !visited[row][col-1] && grid[row][col-1] == 1)
                {
                    grid[row][col-1]=2;
                    visited[row][col-1]=1;
                    q.push(pair<int,pair<int,int>>(depth+1,pair<int,int>(row,col-1)));
                }

                if(row + 1 < n && !visited[row+1][col] && grid[row+1][col] == 1)
                {
                    grid[row+1][col]=2;
                    visited[row+1][col]=1;
                    q.push(pair<int,pair<int,int>>(depth+1,pair<int,int>(row+1,col)));
                }

                if(col + 1 < m && !visited[row][col+1] && grid[row][col+1] == 1)
                {
                    grid[row][col+1]=2;
                    visited[row][col+1]=1;
                    q.push(pair<int,pair<int,int>>(depth+1,pair<int,int>(row,col+1)));
                }           
        }
        return depth;

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        queue<pair<int,pair<int,int>>> q;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2 && !visited[i][j])
                {
                    q.push(pair<int,pair<int,int>>(0,pair<int,int>(i,j)));
                    visited[i][j]=1;
                }
            }
        }

        ans=bfs(n,m,visited,q,grid);


        // to check if any fresh orange remains behind

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};