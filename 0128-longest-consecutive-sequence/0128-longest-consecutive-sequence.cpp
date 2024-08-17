class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        map<int,int> mp;
        for(int i=0;i < nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        map<int,int> :: iterator it;
        int length=1;
        for(it=mp.begin();it!=mp.end();it++)
        {
            int target=it->first + 1;
            if(mp.count(target))
            {
                length++;
            }
            else
            {
                ans.push_back(length);
                length=1;
            }
        }
        ans.push_back(length);
        return *max_element(ans.begin(),ans.end());
    }
};