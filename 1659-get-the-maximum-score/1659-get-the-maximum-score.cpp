class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),i=0;
        int m=nums2.size(),j=0;
        long long sum1 = 0,sum2=0;
        long long ans=0 , mod =1e9 + 7;
        while(i < n && j < m)
        {
            if(nums1[i] == nums2[j])
            {
                ans+=max(sum1,sum2) + nums1[i];
                sum1=0;
                sum2=0;
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                sum1+=nums1[i++];
            }
            else
            {
                sum2+=nums2[j++];
            }
        }
        while(j < m)
        {
            sum2+=nums2[j++];
        }
        while(i < n)
        {
            sum1+=nums1[i++];
        }
        return (ans + max(sum1,sum2)) % mod;
    }
};