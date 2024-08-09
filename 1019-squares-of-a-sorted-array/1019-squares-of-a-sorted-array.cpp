class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0,right=nums.size() - 1;
        vector<int> ans;
        while(left <= right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans.push_back(pow(nums[left++] , 2));
            } 
            else
            {
                ans.push_back(pow(nums[right--] , 2));
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};