class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);

        for(int i=0;i < prerequisites.size();i++)
        {
            int course=prerequisites[i][0];
            int prerequisite=prerequisites[i][1];
            adjlist[prerequisite].push_back(course);
        }
        
        vector<int> order;
        vector<int> indegree(numCourses,0);
        
        for(int i=0;i<adjlist.size();i++)
        {
            for(int j=0;j<adjlist[i].size();j++)
            {
                indegree[adjlist[i][j]]++;
            }
        }

        queue<int> q;
        // pushing the vertices with 0 indegree to the queue
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
            order.push_back(node);
        }

        if(order.size() < numCourses)
        {
            return vector<int>();
        }

        return order;
    }
};