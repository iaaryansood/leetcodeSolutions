class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int start=i+1,end=nums.size() - 1;
            while(start < end)
            {
                int sum=nums[i] + nums[start] + nums[end];
                if(sum == 0)
                {
                    ans.push_back({nums[i] , nums[start] , nums[end]});
                
                    int low=nums[start],high=nums[end];
                    while(start < end && nums[start] == low)
                    {
                        low++;
                    }
                    while(start < end && nums[end] == high)
                    {
                        end--;
                    }
                }
                else if(sum > 0)
                {
                    end--;
                }
                else if(sum < 0)
                {
                    start++;
                }
            }

        }
        return ans;
    }
};