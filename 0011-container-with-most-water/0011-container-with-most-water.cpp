class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size() - 1;
        int maxarea=0;
        while(left < right)
        {
            int currentarea=0;
            if(height[left] < height[right])
            {
                currentarea=height[left] * (right - left);
                left++;
            }
            else
            {
                currentarea=height[right] * (right - left);
                right--;
            }
            if(currentarea > maxarea)
            {
                maxarea=currentarea;
            }
        }
        return maxarea;
    }
};