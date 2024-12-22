class Solution {
public:
    int robLinear(vector<int> nums,int start,int end)
    {
        vector<int> dp(end-start+1,-1);
        int n=end-start+1;
        if(n == 1)
        {
            return nums[start];
        }
        else if(n == 2)
        {
            return max(nums[start],nums[start+1]);
        }
        else
        {
            dp[0] = nums[start];
            dp[1] = max(nums[start],nums[start+1]);
            for(int i=2;i<n;i++)
            {
                dp[i] = max(dp[i-1],dp[i-2] + nums[start+i]);
            }
            return dp[n-1];
        }
        
    }
    int rob(vector<int>& nums) {
            int n=nums.size();
            if(n == 1) 
            {
                return nums[0];
            }
            else if(n == 2)
            {
                return max(nums[0],nums[1]);
            }
            else
            {
                cout<<n<<endl;
                // cout<<robLinear(nums,1,n-1)<<" "<<robLinear(nums,0,n-2);
                return max(robLinear(nums,1,n-1),robLinear(nums,0,n-2));
            }
    }
};