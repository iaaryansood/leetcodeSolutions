class Solution {
public:

    int helper(int a,int b)
    {
        if(a == 0)
        {
            return b;
        }
        else
        {
            return helper(b%a,a);
        }
    }
    int findGCD(vector<int>& nums) {
        int a=*min_element(nums.begin(),nums.end());

        int b=*max_element(nums.begin(),nums.end());

        return helper(a,b);
    }
};