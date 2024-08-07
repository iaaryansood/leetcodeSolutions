#include<algorithm>
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum % 3 != 0)
        {
            return false;
        }
        int target=sum/3;
        int count=0;
        int tempSum=0;
        // cout<<target;
        for(int i=0;i<arr.size();i++)
        {
            tempSum+=arr[i];
            if(tempSum == target)
            {
                count+=1;
                tempSum=0;
            }
        }
        if(count >= 3)
        {
            return true;
        }   
        return false;
    }
};