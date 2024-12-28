class Solution {
public:
    bool helper(vector<int> &arr,vector<vector<int>> &dp,int target,int i,int n)
    {
        if(target == 0)
        {
            return true;
        }
        if(target < 0 || i >= n)
        {
            return false;
        }
        if(dp[target][i] != -1)
        {
            return dp[target][i];
        }
        else
        {
            bool include=helper(arr,dp,target-arr[i],i+1,n);
            bool exclude = helper(arr,dp,target,i+1,n);
            return dp[target][i]=include || exclude;
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum % 2 != 0)
        {
            return false;
        }
        int n = nums.size();
        int target = sum/2;
        vector<vector<int>> dp(target + 1,vector<int>(n,-1));
        return helper(nums,dp,target,0,n);
    }
};