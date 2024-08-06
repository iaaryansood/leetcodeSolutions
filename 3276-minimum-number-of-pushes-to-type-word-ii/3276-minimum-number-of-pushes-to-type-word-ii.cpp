#include<vector>
class Solution {
public:
    int minimumPushes(string word) {
    vector<int> frequency(26,0);
    for(int i=0;i<word.size();i++)
    {
        frequency[word[i] - 'a']++;
    }
    sort(frequency.begin(),frequency.end());
    reverse(frequency.begin(),frequency.end());
    int count=0;
    for(int i=0;i<frequency.size();i++)
    {
        if(frequency[i] == 0) break;
        count+=(i/8 + 1) * frequency[i];
    }
    return count;
    // for(int i=0;i<frequency.size();i++)
    // {
    //     cout<<frequency[i]<<" ";
    // }
    // return 0;
    }
};