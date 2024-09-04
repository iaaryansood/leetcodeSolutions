class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                    if(board[i][j] == 'O')
                    {
                        visited[i][j]=1;
                        q.push(pair<int,int>(i,j));
                    }
                }
            }
        }

        vector<pair<int,int>> directions={{-1,0},{0,1},{1,0},{0,-1}};

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

                if(delrow >= 0 && delcol >= 0 && delrow < n && delcol < m && !visited[delrow][delcol])
                {
                    if(board[delrow][delcol] == 'O')
                    {
                         visited[delrow][delcol]=1;
                        q.push(pair<int,int>(delrow,delcol));
                    }  
                }
            }
            
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j]='X';
                }
            }
        }

        return;
    }
};
