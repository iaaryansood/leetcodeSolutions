#include <vector>
#include <cstdlib> // For rand()
#include <algorithm> // For swap()

using namespace std;

class Solution {
public:
    // Helper function to compute squared distance
    int squaredDistance(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    // Partition function similar to QuickSort
    int partition(vector<vector<int>>& points, int start, int end) {
        int pivotDist = squaredDistance(points[start]);
        int countSmaller = 0;

        // Count how many points have a distance less than the pivot
        for (int i = start + 1; i <= end; i++) {
            if (squaredDistance(points[i]) < pivotDist) {
                countSmaller++;
            }
        }

        // Move pivot to its correct position
        int pivotIndex = start + countSmaller;
        swap(points[start], points[pivotIndex]);

        // Arrange points so that points less than pivot are on the left
        int i = start, j = end;
        while (i < pivotIndex && j > pivotIndex) {
            if (squaredDistance(points[i]) < pivotDist) {
                i++;
            } else if (squaredDistance(points[j]) >= pivotDist) {
                j--;
            } else {
                swap(points[i], points[j]);
                i++;
                j--;
            }
        }
        return pivotIndex;
    }

    // QuickSelect function to find k closest points
    void quickSelect(vector<vector<int>>& points, int start, int end, int k) {
        if (start >= end) {
            return;
        }

        int pivotIndex = partition(points, start, end);

        // If pivot is at the kth position, we're done
        if (pivotIndex == k - 1) {
            return;
        } else if (pivotIndex > k - 1) {
            quickSelect(points, start, pivotIndex - 1, k);
        } else {
            quickSelect(points, pivotIndex + 1, end, k);
        }
    }

    // Main function to find k closest points
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size() - 1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
