class Solution {
public:

    int squareDistance(vector<int> points)
    {
        return points[0] * points[0] + points[1] * points[1];
    }

    void quickSelect(vector<vector<int>> & points,int left,int right,int k)
    {
        if(left >= right)
        {
            return;
        }
        else
        {
            int pivotIndex=left + rand() % (right-left+1);
            int pivotDistance=squareDistance(points[pivotIndex]);

            swap(points[right],points[pivotIndex]);

            int storeIndex=left;

            for(int i=left;i < right;i++)
            {
                if(squareDistance(points[i]) <= pivotDistance)
                {
                    swap(points[storeIndex],points[i]);
                    storeIndex++;
                }
            }

            swap(points[storeIndex],points[right]);

            int leftIndex=storeIndex-left+1;

            if(leftIndex == k)
            {
                return;
            }
            else if(leftIndex < k)
            {
                quickSelect(points,storeIndex+1,right,k-leftIndex);
            }
            else
            {
                quickSelect(points,left,storeIndex-1,k);
            }
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points,0,points.size()-1,k);
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};