class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,vector<vector<int>>> map;
        for(int i=0;i<points.size();i++)
        {
            int sum=0;
            for(int j=0;j<points[i].size();j++)
            {
                sum+=pow(points[i][j],2);
            }
            pq.push(sum);
            map[sum].push_back(points[i]);
        }
        vector<vector<int>> ans;
        while(k)
        {
            int dist=pq.top();
            pq.pop();
            for(auto point : map[dist])
            {
                ans.push_back(point);
                k--;
                if(k == 0) break;
            }
        }
        return ans;
    }
};