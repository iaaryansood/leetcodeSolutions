#include<unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> :: iterator it;
        for(it= map.begin();it != map.end();it++)
        {
            pair<int,int> temp;
            temp.first=it->second;
            temp.second=it->first;
            pq.push(temp);
        }
        vector<int> ans;
        while(k > 0)
        {
            pair<int,int> temp=pq.top();
            ans.push_back(temp.second);
            pq.pop();
            k--;
        }
        return ans;
    }
};