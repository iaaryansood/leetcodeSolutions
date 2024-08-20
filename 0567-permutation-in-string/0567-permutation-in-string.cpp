class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
        return false;

        unordered_map<char,int> s1map;
        for(int i=0;i<s1.size();i++)
        {
            s1map[s1[i]]++;
        }

        unordered_map<char,int> s2map;

        for(int i=0;i < s1.size();i++)
        {
            s2map[s2[i]]++;
        }

        if(s1map == s2map)
        return true;

        for(int i=s1.size();i<s2.size();i++)
        {
            char newChar=s2[i];
            s2map[newChar]++;
            char oldChar=s2[i-s1.size()];
            if(s2map[oldChar] == 1)
            {
                s2map.erase(oldChar);
            }
            else
            {
                s2map[oldChar]--;
            }
            if(s1map == s2map)
            return true;
        }
        return false;
    }
};