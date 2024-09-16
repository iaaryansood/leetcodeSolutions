class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,1e8));
        
        // making the adjacency matrix
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];

            distance[u][v]=weight;
            distance[v][u]=weight;
        }

        for(int i=0;i<distance.size();i++)
        {
            distance[i][i]=0;
        }

        // applying floyd warshal algorithm

        for(int var=0;var<n;var++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    distance[i][j]=min(distance[i][j],distance[i][var] + distance[var][j]);
                }
            }
        }
        int ans=0;
        int count=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int currcount=0;
            for(int j=0;j<n;j++)
            {
                if(distance[i][j] <= distanceThreshold)
                {
                    currcount++;
                }
            }
            if(currcount <= count)
            {
                count=currcount;
                ans=i;
            }
        }
        return ans;

        



    }
};