class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int> final(n+m,0);
        int i=0,j=0,k=0;
        while(i < n && j < m)
        {
            if(nums1[i] < nums2[j])
            {
                final[k++]=nums1[i++];
            }
            else
            {
                final[k++]=nums2[j++];
            }
        }

        while(i < n)
        {
            final[k++]=nums1[i++];
        }

        while(j < m)
        {
            final[k++]=nums2[j++];
        }
        int finalSize=n+m;
        double ans;
        if(finalSize % 2 != 0)
        {
            return (double)final[(finalSize - 1)/2];
        }
        else
        {
            ans = (final[(finalSize - 2 )/2] + final[(finalSize/2)])/2.0;
        }
        return ans;
    }
};