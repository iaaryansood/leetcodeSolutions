class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1)
        return 0;

        vector<bool> nums(n,true);
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(nums[i])
            {
                count++;
                int j=2;
                while(i * j < n)
                {
                    nums[i*j]=false;
                    j++;
                }
            }

        }
        return count;
    }
};