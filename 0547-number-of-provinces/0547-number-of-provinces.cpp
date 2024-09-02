class Solution {
public:

    void dfs(int node,vector<int> &visited,vector<vector<int>> &isConnected)
    {
        visited[node]=1;
        for(int i=0;i<isConnected[node].size();i++)
        {
            if(isConnected[node][i] == 1 && !visited[i])
            {
                dfs(i,visited,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();

        vector<int> visited(v,0);
        int numIslands=0;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                // cout<<i<<endl;
                numIslands++;
                dfs(i,visited,isConnected);
            }
        }
        return numIslands;
    }
};