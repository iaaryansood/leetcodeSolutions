class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxarea = 0;

        while (left < right) {
            // Calculate area and update maxarea in one step
            maxarea = max(maxarea, min(height[left], height[right]) * (right - left));
            
            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxarea;
    }
};
