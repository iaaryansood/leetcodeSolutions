class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back(pair<int,int>(flights[i][1],flights[i][2]));
        }

        vector<int> distance(n,INT_MAX);
        distance[src]=0;

        queue<pair<int,pair<int,int>>> q;
        q.push(pair<int,pair<int,int>>(0,pair<int,int>(src,0)));
        
        while(!q.empty())
        {
            pair<int,pair<int,int>> p=q.front();
            q.pop();

            int stops=p.first;
            int node=p.second.first;
            int rootDistance=p.second.second;
            if(stops > k)
            continue;


            for(int i=0;i<adj[node].size();i++)
            {
                pair<int,int> p=adj[node][i];
                int temp=p.first;
                int tempDistance=p.second;

                if((tempDistance + rootDistance < distance[temp]) && stops <= k)
                {
                    distance[temp]=tempDistance + rootDistance;
                    q.push(pair<int,pair<int,int>>(stops + 1,pair<int,int>(temp,distance[temp])));
                }
            }
        }
        if(distance[dst] == INT_MAX)
        {
            return -1;
        }
        return distance[dst];
    }
};