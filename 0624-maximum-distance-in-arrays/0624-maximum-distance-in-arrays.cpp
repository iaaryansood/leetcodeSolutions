class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int global_min=arrays[0][0];
        int global_max=arrays[0][arrays[0].size() - 1];
        int ans = 0;
        for(int i=1;i < arrays.size();i++)
        {
            int temp1=abs(arrays[i][arrays[i].size() - 1] - global_min);
            int temp2=abs(arrays[i][0] - global_max);
            ans =max(ans,max(temp1,temp2));

            // update global maximum
            global_max=max(global_max,arrays[i][arrays[i].size() - 1]);
            global_min=min(global_min,arrays[i][0]);
        }
        return ans;
    }
};