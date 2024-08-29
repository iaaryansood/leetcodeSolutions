class Solution {
public:

    int squareDistance(vector<int> point)
    {
        return point[0] * point[0] + point[1] * point[1]; 
    }

    void quickselect(vector<vector<int>> &points,int left,int right,int k)
    {
        if(left >= right)   return;

        int pivotIndex=left + rand() % (right-left+1);
        int pivotDistance=squareDistance(points[pivotIndex]);

        swap(points[right],points[pivotIndex]);
        int storeIndex=left;

        for(int i=left;i<right;i++)
        {
            if(squareDistance(points[i]) <= pivotDistance)
            {
                swap(points[i],points[storeIndex]);
                storeIndex++;
            }
        }
        swap(points[right],points[storeIndex]);

        int leftCount=storeIndex-left+1;
        if(leftCount == k)
        {
            return;
        }
        else if(leftCount < k)
        {
            quickselect(points,storeIndex+1,right,k-leftCount);
        }
        else
        {
            quickselect(points,left,storeIndex-1,k);
        }

    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickselect(points,0,points.size()-1,k);
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};