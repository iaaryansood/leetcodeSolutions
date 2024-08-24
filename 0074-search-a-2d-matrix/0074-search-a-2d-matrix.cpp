class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int columns=matrix[0].size();
        int start=0,end=rows*columns - 1;
        while(start <= end)
        {
            int mid=start+(end-start)/2;
            if(target == matrix[mid/columns][mid%columns])
            {
                return true;
            }
            else if(matrix[mid/columns][mid%columns] < target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return false;
    }
};