class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        ans[0][0]=0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push(pair<int,pair<int,int>>(0,pair<int,int>(0,0)));

        while(!pq.empty())
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();

            int rootDiff=p.first;
            int row=p.second.first;
            int col=p.second.second;
            // if(row == n-1 && col == m-1)
            // {
            //     return rootDiff;
            // }
            vector<int> dx={0,-1,0,1};
            vector<int> dy={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int delrow=row + dx[i];
                int delcol=col + dy[i];

                if(delrow >=0 && delcol >=0 && delrow < n && delcol < m)
                {
                    int tempDiff=abs(heights[delrow][delcol] - heights[row][col]);
                    int effort=max(tempDiff,rootDiff);

                    if(effort < ans[delrow][delcol])
                    {
                        ans[delrow][delcol]=effort;
                        pq.push(pair<int,pair<int,int>>(ans[delrow][delcol],pair<int,int>(delrow,delcol)));
                    }
                }
            }
        }
        return ans[n-1][m-1];
    }
};