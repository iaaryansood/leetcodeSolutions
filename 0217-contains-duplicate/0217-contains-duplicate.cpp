#include<unordered_map>
class Solution {
public:
    unordered_map<int,int> map;
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(!map.count(nums[i]))
            {
                map[nums[i]]++;
            }
            else
            {
                return true;
            }
        }
        return false;
        
    }
};