class Solution {
public:
    void subset(vector<int> nums,vector<int> output,vector<vector<int>> &ans)
    {
        if(nums.size() == 0)
        {
            ans.push_back(output);
        }
        else
        {
            int temp=nums[0];
            nums.erase(nums.begin());
            subset(nums,output,ans);
            output.push_back(temp);
            subset(nums,output,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        subset(nums,output,ans);
        return ans;
    }
};