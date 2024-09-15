class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);

        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(pair<int,long long>(roads[i][1],roads[i][2]));
            adj[roads[i][1]].push_back(pair<int,long long>(roads[i][0],roads[i][2]));
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});

        vector<int> count(n,0);
        count[0]=1;

        vector<long long> distance(n,LLONG_MAX);
        distance[0]=0;

        int MOD=1e9 + 7;

        while(!pq.empty())
        {
            pair<long long,int> p=pq.top();
            pq.pop();

            long long rootDistance=p.first;
            int node=p.second;

            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i].first;
                long long edgeWeight=adj[node][i].second;

                if(rootDistance + edgeWeight < distance[temp])
                {
                    distance[temp]=rootDistance + edgeWeight;
                    pq.push(pair<long long,int>(distance[temp],temp));
                    count[temp]=count[node];
                }
                else if(rootDistance + edgeWeight == distance[temp])
                {
                    count[temp]=(count[temp] + count[node]) % MOD;
                }
            }
        }
        return count[n-1];
    }
};