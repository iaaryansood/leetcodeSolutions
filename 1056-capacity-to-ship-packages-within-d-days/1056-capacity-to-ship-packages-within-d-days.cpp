class Solution {
public:
    bool isPossible(vector<int> &weights,int days,int max_weight)
    {
        int current_weight=0,current_days=1;
        for(int i=0;i<weights.size();i++)
        {
            if(current_weight + weights[i] <= max_weight)
            {
                current_weight+=weights[i];
            }
            else if(current_weight + weights[i] > max_weight)
            {
                current_weight=weights[i];
                current_days++;
            }
            if(current_days > days || current_weight > max_weight)
            {
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0,end=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        int mid=start+(end-start)/2;
        // cout<<start<<" "<<ans<<" "<<end<<endl;
        while(start <= end)
        {
            cout<<start<<" "<<mid<<" "<<end<<endl;
            if(isPossible(weights,days,mid))
            {
                ans=mid;
                
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};