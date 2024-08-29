#include <vector>
#include <cstdlib> // For rand()
#include <algorithm> // For swap()

using namespace std;

class Solution {
public:
    // Helper function to compute the squared distance from the origin
    int squaredDistance(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    // Quickselect function
    void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
        if (left >= right) return;

        // Choose a random pivot
        int pivotIndex = left + rand() % (right - left + 1);
        int pivotDist = squaredDistance(points[pivotIndex]);

        // Move pivot to the end
        swap(points[pivotIndex], points[right]);
        int storeIndex = left;

        // Partition the list
        for (int i = left; i < right; ++i) {
            if (squaredDistance(points[i]) <= pivotDist) {
                swap(points[storeIndex], points[i]);
                ++storeIndex;
            }
        }
        // Move pivot to its final place
        swap(points[right], points[storeIndex]);

        // Recursively find the k closest points
        int leftCount = storeIndex - left + 1;
        if (k < leftCount) {
            quickSelect(points, left, storeIndex - 1, k);
        } else if (k > leftCount) {
            quickSelect(points, storeIndex + 1, right, k - leftCount);
        }
    }

    // Main function to find k closest points
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size() - 1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
