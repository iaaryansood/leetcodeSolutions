class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // optimised approach using monotonic stack
        stack<int> s;
        vector<int> ans(temperatures.size());
        for(int i=0;i<temperatures.size();i++)
        {
            while(!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;

        
    }
};