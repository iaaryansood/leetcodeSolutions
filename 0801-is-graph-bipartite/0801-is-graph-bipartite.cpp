class Solution {
private:
    bool check(int n,vector<int> &color,queue<int> &q,vector<vector<int>> &graph)
    {
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(int i=0;i<graph[node].size();i++)
            {
                int temp=graph[node][i];
                if(color[temp] == -1)
                {
                    color[temp]=!color[node];
                    q.push(temp);
                }
                else if(color[temp] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> color(n,-1);

        queue<int> q;

        for(int i=0;i<n;i++)
        {
            if(color[i] == -1)
            {
                q.push(i);
                color[i]=0;
                if(check(n,color,q,graph) == false)
                {
                    return false;
                }
            }
        }
        return true;

    }
};