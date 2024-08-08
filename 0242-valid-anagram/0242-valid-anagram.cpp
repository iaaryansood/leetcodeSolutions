#include<unordered_map>
class Solution {
public:
    unordered_map<char,int> map;
    bool isAnagram(string s, string t) {
        for(int i=0;i<s.size();i++)
        {
            map[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            map[t[i]]--;
            cout<<map[t[i]]<<" ";
        }
        for(int i=0;i<map.size();i++)
        {
            if(map[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};