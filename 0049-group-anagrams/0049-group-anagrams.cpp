#include<unordered_map> 
#include<vector>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            map[temp].push_back(strs[i]);
        }
        unordered_map<string,vector<string>> :: iterator it=map.begin();
        vector<vector<string>> ans;
        while(it != map.end())
        {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};