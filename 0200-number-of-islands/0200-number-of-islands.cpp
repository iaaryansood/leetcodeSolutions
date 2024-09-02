class Solution {
    private : 
    void bfs(queue<pair<int,int>> &q,vector<vector<char>> &grid,vector<vector<int>> &visited,int m,int n)
    {
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();

            int i=temp.first;
            int j=temp.second;

            if(i - 1 >= 0 && grid[i-1][j] - '0' && !visited[i-1][j])   //up
            {
                q.push(pair<int,int>(i-1,j));
                visited[i-1][j]=1;              //as visited is defined true when it is pushed onto the queue
            }

            if(j - 1 >= 0 && grid[i][j-1] - '0' &&  !visited[i][j-1])   //left
            {
                q.push(pair<int,int>(i,j-1));
                visited[i][j-1]=1;

            }

            if(i+1 < m && grid[i+1][j] - '0' &&  !visited[i+1][j])      //down
            {
                q.push(pair<int,int>(i+1,j));
                visited[i+1][j]=1;
            }

            if(j+1 < n && grid[i][j+1] - '0' && !visited[i][j+1])     //right
            {
                q.push(pair<int,int>(i,j+1));
                visited[i][j+1]=1;
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int countIslands=0;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] - '0')
                {
                    if(!visited[i][j])
                    {
                        q.push(pair<int,int>(i,j));
                        visited[i][j]=1;
                        countIslands++;
                        bfs(q,grid,visited,m,n);
                    }
                }
            }
        }
        return countIslands;

    }
};