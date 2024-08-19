class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> map;
        int maxlen=0;
        int start=0;
        for(int i=0;i<s.size();i++)
        {
            if(map.find(s[i]) != map.end() && map[s[i]] >= start)
            {
                start=map[s[i]] + 1;
            }
            map[s[i]]=i;
            maxlen=max(maxlen,i-start+1);
        }
        return maxlen;
    }
};