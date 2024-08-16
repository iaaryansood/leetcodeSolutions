class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int count=1;
        for(int layers=0;layers < (n + 1) / 2 ; layers++)
        {
            //Traversal from left to right in a constant row
            for(int ptr=layers;ptr < n - layers;ptr++)
            {
                ans[layers][ptr]=count++;
            }

            // Traversal from up to down in a constant column
            for(int ptr = layers + 1;ptr < n - layers;ptr++)
            {
                ans[ptr][n - layers - 1]=count++;
            }

            // Traversal from right to left in a constant row
            for(int ptr=n - layers - 2;ptr >= layers;ptr--)
            {
                ans[n - layers - 1][ptr]=count++;
            } 

            // Traversal from down to up in a constant column
            for(int ptr=n-layers - 2;ptr > layers;ptr--)
            {
                ans[ptr][layers]=count++;
            }
        }
        return ans;
    }
};