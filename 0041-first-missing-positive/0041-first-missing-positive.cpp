class Solution {
public:
    
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0)
            {
                map[nums[i]]++;
            }   
        }
        int ans=1;
        for(auto it:map)
        {
            // cout<<it.first<<" ";
            if(it.first == ans)
            {
                ans++;
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};