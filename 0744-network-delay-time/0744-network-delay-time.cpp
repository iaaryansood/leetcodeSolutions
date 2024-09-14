class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> distance(n+1,INT_MAX);
        distance[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();

            int rootTime=p.first;
            int node=p.second;

            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i].first;
                int edgeWeight=adj[node][i].second;

                if(rootTime + edgeWeight < distance[temp])
                {
                    distance[temp]=rootTime + edgeWeight;
                    pq.push({distance[temp],temp});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<distance.size();i++)
        {
            cout<<distance[i]<<" ";
            if(distance[i] == INT_MAX)
            {
                return -1;
            }
            ans=max(ans,distance[i]);
        }
        return ans;
    }
};