class Solution {
public:
    int trailingZeroes(int n) {
        int divide=5;
        int ans=0;
        while(n / divide)
        {
            ans+=floor(n/divide);
            divide=divide * 5;
        }
        return ans;
    }
};