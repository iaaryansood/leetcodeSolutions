#include<unordered_map>
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
            if(map[nums[i]] == 2)
            {
                ans.push_back(nums[i]);
            }
            
        }
        return ans;
    }
};