class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adjlist, vector<int> &visited) {
        visited[node] = 1;  // Mark the node as being visited (part of the current path)

        for (int temp : adjlist[node]) {
            if (visited[temp] == 0) {
                // If the node has not been visited yet, recursively visit it
                if (dfs(temp, adjlist, visited)) {
                    return true;  // A cycle was detected
                }
            } else if (visited[temp] == 1) {
                // If the node is currently being visited, a cycle is detected
                return true;
            }
        }

        visited[node] = 2;  // Mark the node as fully processed
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<int> visited(numCourses, 0);

        // Construct the adjacency list
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            adjlist[course].push_back(prerequisite);
        }

        // Perform DFS for each unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adjlist, visited)) {
                    return false;  // A cycle was detected
                }
            }
        }
        return true;  // No cycle was detected
    }
};
