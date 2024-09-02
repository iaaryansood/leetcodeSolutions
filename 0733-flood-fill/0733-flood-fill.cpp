class Solution {
public:

    void dfs(int sr,int sc,int initialColor,vector<vector<int>> &visited,vector<vector<int>> &image,vector<vector<int>> &ans,int color)
    {
        ans[sr][sc]=color;
        visited[sr][sc]=1;

        if(sr - 1 >= 0 && !visited[sr - 1][sc] && image[sr-1][sc] == initialColor)
        {
            visited[sr-1][sc]=1;
            dfs(sr-1,sc,initialColor,visited,image,ans,color);
        }

        if(sc - 1 >= 0 && !visited[sr][sc-1] && image[sr][sc-1] == initialColor)
        {
            visited[sr][sc-1]=1;
            dfs(sr,sc-1,initialColor,visited,image,ans,color);
        }

        if(sr + 1 < image.size() && !visited[sr+1][sc] && image[sr+1][sc] == initialColor)
        {
            visited[sr+1][sc]=1;
            dfs(sr+1,sc,initialColor,visited,image,ans,color);
        }

        if(sc + 1 < image[0].size() && !visited[sr][sc+1] && image[sr][sc+1] == initialColor)
        {
            visited[sr][sc+1]=1;
            dfs(sr,sc+1,initialColor,visited,image,ans,color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor=image[sr][sc];

        int n=image.size();
        int m=image[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        vector<vector<int>> ans=image;

        dfs(sr,sc,initialColor,visited,image,ans,color);

        return ans;
    }
};