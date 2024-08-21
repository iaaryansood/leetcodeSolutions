class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> map;
        for(int i=0;i<deck.size();i++)
        {
            map[deck[i]]++;
        }

        int res=0;
        unordered_map<int,int> :: iterator it;
        for(it=map.begin();it!=map.end();it++)
        {
            res=__gcd(it->second,res);
        }
        return res > 1;
    }
};