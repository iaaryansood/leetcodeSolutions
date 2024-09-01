class Solution {
public:
    long long int calculateSum(int num)
    {
        long long int sum=0;
        while(num > 0)
        {
            int digit=num%10;
            sum+=digit * digit;
            num=num/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<long long int> set;
        long long int sum=calculateSum(n);
        while(sum != 1 && set.find(sum) == set.end())
        {
            set.insert(sum);
            sum=calculateSum(sum);
            if(sum == 1)
            {
                return true;
            }
        }
        return sum == 1;
    }
};