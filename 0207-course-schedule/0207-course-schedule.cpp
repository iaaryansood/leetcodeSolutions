class Solution {
private :
    bool dfs(int node,vector<vector<int>> &adjlist,vector<int> &visited)
    {
        visited[node]=1;

        for(int i=0;i<adjlist[node].size();i++)
        {
            int temp=adjlist[node][i];
            if(visited[temp] == 0)
            {
                // visited[temp]=1;
                if(dfs(temp,adjlist,visited))
                {
                    return true;
                }
            }
            else if(visited[temp] == 1)
            {
                return true;
            }
        }
        visited[node]=2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);

        vector<vector<int>> adjlist(numCourses);

        for(int i=0;i<prerequisites.size();i++)
        {
            for(int j=0;j<prerequisites[i].size();j++)
            {
                int course=prerequisites[i][0];
                int prerequisite=prerequisites[i][1];
                adjlist[course].push_back(prerequisite);
            }
        }

        for(int i=0;i<visited.size();i++)
        {
            if(visited[i] == 0)
            {
                if(dfs(i,adjlist,visited))
                {
                    return false;
                }
            }
        }
        return true;
    }
};