// Solution using topological sort
class Solution {
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
                adjlist[prerequisite].push_back(course);
            }
        }

        vector<int> ans;
        vector<int> indegree(numCourses,0);

        for(int i=0;i<adjlist.size();i++)
        {
            for(int j=0;j<adjlist[i].size();j++)
            {
                indegree[adjlist[i][j]]++;
            }
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(int i=0;i<adjlist[node].size();i++)
            {
                int temp=adjlist[node][i];
                indegree[temp]--;
                if(indegree[temp] == 0)
                {
                    q.push(temp);
                }
            }
            ans.push_back(node);
        }
        return (ans.size() == numCourses);
    }
};