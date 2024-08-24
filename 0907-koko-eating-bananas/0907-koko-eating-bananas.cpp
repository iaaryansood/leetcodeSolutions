class Solution {
public:

    int isenough(vector<int> piles,double k)
    {
        int ans=0;
        for(int i=0;i<piles.size();i++)
        {
            ans+=ceil(piles[i]/k);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left < right)
        {
            double mid=left+(right-left)/2;
            // cout<<left<<" "<<mid<<" "<<right<<endl;
            int required=isenough(piles,mid);
            // cout<<"required : "<<required<<endl;
            if(required <= h)
            {
                right=mid;
            }
            else if(required > h)
            {
                left=mid+1;
            }
        }
        return left;
    }
};