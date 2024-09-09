class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<vector<int>> adj(graph.size());

        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int temp=graph[i][j];
                adj[temp].push_back(i);
            }
        }

        vector<int> indegree(adj.size(),0);
        queue<int> q;
        
        // filling the indegree vector
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]++;
            }
        }

        // finding vertices with zero indegree
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<" ";
            q.pop();

            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i];
                indegree[temp]--;
                if(indegree[temp] == 0)
                {
                    q.push(temp);
                }
            }
            ans.push_back(node);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }

};