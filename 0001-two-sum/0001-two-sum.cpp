#include<unordered_map>
class Solution {
public:
    unordered_map<int,int> map;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(map.count(target - nums[i]) && map[target - nums[i]] != i)
            {
                ans.push_back(i);
                ans.push_back(map[target - nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};