class Solution {
public:
    bool isPowerOfTwo(int n) {
        // n=abs(n);
        long long int temp=1;
        while(temp != n && temp < n)
        {
            temp=temp<<1;
        }
        return temp == n;
    }
};