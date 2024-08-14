class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        // Calculate the minimum possible gap (bucket size)
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));

        // Number of buckets needed
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        // Buckets to store min and max values in each bucket
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        // Place each number in a bucket
        for (int num : nums) {
            int bucketIdx = (num - minVal) / bucketSize;
            bucketMin[bucketIdx] = min(bucketMin[bucketIdx], num);
            bucketMax[bucketIdx] = max(bucketMax[bucketIdx], num);
        }

        // Find the maximum gap
        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; i++) {
            // Skip empty buckets
            if (bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN) continue;

            // Calculate the gap
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};
