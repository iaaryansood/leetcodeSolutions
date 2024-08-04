class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n == 1)
        {
            return 0;
        }
        int count=0;
        vector<bool> prime(n,true);
        for(int i=2;i<n;i++)
        {
            if(prime[i])
            {
                count++;
                int j=2;
                while(i * j < n)
                {
                    prime[i*j]=false;
                    j++;
                }
            }
        }
        return count;
    }
};