class Solution {
private: 
    bool dfs(int node,vector<int> &visited,vector<int> &pathVisited,vector<vector<int>> &adjlist,vector<int> &order)
    {
        visited[node]=1;
        pathVisited[node]=1;

        for(int i=0;i<adjlist[node].size();i++)
        {
            int temp=adjlist[node][i];

            if(visited[temp] == 0)
            {
                if(dfs(temp,visited,pathVisited,adjlist,order))
                {
                    return true;
                }
            }
            else if(pathVisited[temp] == 1)
            {
                return true;
            }
        }
        pathVisited[node]=0;
        order.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);

        vector<int> courses;
        vector<vector<int>> adjlist(numCourses);

        for(int i=0;i < prerequisites.size();i++)
        {
            int course=prerequisites[i][0];
            int prerequisite=prerequisites[i][1];
            adjlist[course].push_back(prerequisite);
        }
        
        vector<int> order;
        // starting the traversal
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited,pathVisited,adjlist,order))
                {
                    return vector<int>();
                }
            }
        }
        return order;
    }
};