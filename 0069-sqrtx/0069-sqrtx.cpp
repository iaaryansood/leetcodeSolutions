class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
        {
            return x;
        }
        int start=0,end=x,mid=start+(end-start)/2;
        int ans=0;
        while(start <= end)
        {
            if((long long )mid * mid == x)
            {
                return mid;
            }
            else if((long long )mid * mid < x)
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};