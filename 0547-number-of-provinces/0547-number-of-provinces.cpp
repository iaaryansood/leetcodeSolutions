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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j])
                {
                    ds.unionBySize(i,j);
                }
                
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUltimateParent(i) == i)
            {
                count++;
            }
        }
        return count;
    }
};