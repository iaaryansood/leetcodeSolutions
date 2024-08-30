class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(auto temp : tasks)
        {
            freq[temp - 'A']++;
        }

        sort(freq.begin(),freq.end());

        int max_freq=freq[25];

        int idle=(max_freq-1) * n;

        for(int i=freq.size() - 2;i >= 0 && idle >=0 ;i--)
        {
            idle=idle - min(max_freq - 1,freq[i]);
        }

        idle=max(idle,0);

        return tasks.size()+idle;
    }
};