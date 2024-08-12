class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int count=floor(nums.size() / 3) + 1;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
            if(map[nums[i]] == count)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};