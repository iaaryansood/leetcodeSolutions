class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUltimateParent(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        else
        {
            return parent[node] = findUltimateParent(parent[node]);
        }
    }
    
    void unionByRank(int u,int v)
    {
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);

        if(ulp_u == ulp_v)
        {
            return;
        }
        else if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u] == rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);

        if(ulp_u == ulp_v)
        {
            return;
        }

        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }   

    }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxRow=INT_MIN;
        int maxCol=INT_MIN;

        for(int i=0;i<stones.size();i++)
        {
            maxRow=max(maxRow,stones[i][0]);
            maxCol=max(maxCol,stones[i][1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        for(int i=0;i<stones.size();i++)
        {
            ds.unionBySize(stones[i][0],stones[i][1] + maxRow + 1);
            stoneNodes[stones[i][0]] = 1;
            stoneNodes[stones[i][1] + 1 + maxRow] = 1;
        }

       int count = 0;
        for (auto it : stoneNodes) {
            if (ds.findUltimateParent(it.first) == it.first) {
            count++;
            }
        }

        return stones.size() - count;
    }
};