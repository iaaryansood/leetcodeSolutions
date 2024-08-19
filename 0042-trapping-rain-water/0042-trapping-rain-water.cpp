class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=height[0];
        right[n-1]=height[n-1];

        // calculate the maximum height on the left side of each index
        for(int i=1;i < n;i++)
        {
            left[i]=max(left[i-1],height[i]);
        }

        // Calculate the maximum height on the right of every index
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i]);
        }

        // Calculating trapped rainwater
        int trapped=0;
        for(int i=0;i<n;i++)
        {
            trapped+=(min(left[i],right[i]) - height[i]);
        }
        return trapped;
    }
};