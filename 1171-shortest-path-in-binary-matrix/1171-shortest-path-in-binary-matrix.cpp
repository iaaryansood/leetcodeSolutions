class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
        {
            return -1;
        }
        int n=grid.size();

        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0]=1;

        queue<pair<int,pair<int,int>>> q;
        q.push(pair<int,pair<int,int>>(1,pair<int,int>(0,0)));

        vector<int> dx={-1,-1,-1,0,0,1,1,1};
        vector<int> dy={-1,0,1,-1,1,-1,0,1};
        while(!q.empty())
        {
            pair<int,pair<int,int>> p=q.front();
            q.pop();

            int depth=p.first;
            int row=p.second.first;
            int col=p.second.second;

            // cout<<depth<<" "<<row<<" "<<col<<endl;

            if(row == n-1 && col == n-1)
            {
                return depth;
            }
            for(int i=0;i<8;i++)
            {
                int delrow=row+dx[i];
                int delcol=col+dy[i];

                if(delrow >= 0 && delcol >= 0 && delrow < n && delcol < n)
                {
                    // cout<<delrow<<" "<<delcol<<endl;

                    if(grid[delrow][delcol] == 0 && !visited[delrow][delcol])
                    {
                        q.push(pair<int,pair<int,int>>(depth + 1,pair<int,int>(delrow,delcol)));
                        visited[delrow][delcol]=1;
                    }
                }
            }
        }
        return -1;

    }
};