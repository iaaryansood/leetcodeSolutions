class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD=1000000007;
        vector<int> sums;
        sums.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            sums.push_back( (sums[i-1] + nums[i]) % MOD );
        }
        vector<int> sum_subarray;
        for(int i=0;i< sums.size();i++)
        {
            for(int j=i;j < sums.size();j++)
            {
                if(i == 0)
                {
                    sum_subarray.push_back(sums[j]);
                }
                else
                {
                    sum_subarray.push_back( (sums[j] - sums[i-1] + MOD ) % MOD ) ;
                }
            }
        }
        
        sort(sum_subarray.begin(),sum_subarray.end());
        // for(int i=0;i < sum_subarray.size();i++)
        // {
        //     cout<<sum_subarray[i]<<" ";
        // }
        int sum=0;
        for(int i=left-1;i<= right - 1;i++)
        {
            sum=(sum + sum_subarray[i])%MOD;
        }
        
        return sum%MOD;
    }
};