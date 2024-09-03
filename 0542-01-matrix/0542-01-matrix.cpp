class Solution {
private:
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> distance(n,vector<int>(m,-1));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j]=1;
                    // q.push(pair<pair<int,int>>(i,j),0);
                    q.push(pair<pair<int,int>,int>(pair<int,int>(i,j),0));
                }
            }
        }

        vector<pair<int,int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty())
        {
            pair<pair<int,int>,int> p=q.front();
            q.pop();

            int row=p.first.first;
            int col=p.first.second;
            int depth=p.second;

            distance[row][col]=depth;

            for(int i=0;i<4;i++)
            {
                int delrow=row+directions[i].first;
                int delcol=col+directions[i].second;

                if(delrow >=0 && delcol >= 0 && delrow < n && delcol < m && !visited[delrow][delcol])
                {
                    q.push(pair<pair<int,int>,int>(pair<int,int>(delrow,delcol),depth+1));
                    visited[delrow][delcol]=1;
                }
            }

        }


        return distance;
    }
};