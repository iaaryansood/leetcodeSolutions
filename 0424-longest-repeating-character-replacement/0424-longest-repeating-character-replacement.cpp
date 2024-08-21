class Solution {
public:
    int characterReplacement(string s, int k) {
        // slidding window technique
        int left=0,right=0;
        int n=s.size();
        unordered_map<char,int> map;
        int maxlen=0;
        int maxf=0;
        while(right < n)
        {
            int len=right-left+1;
            map[s[right]]++;
            maxf=max(maxf,map[s[right]]);
            int changes=len-maxf;
            if(changes <= k)
            {
                maxlen=max(maxlen,len);
            }
            else
            {
                map[s[left]]--;
                left++;
                int ans=INT_MIN;
                unordered_map<char,int> :: iterator it;
                for(it=map.begin();it != map.end();it++)
                {
                    if(it->second > ans)
                    {
                        ans=it->second;
                    }
                }
                maxf=ans;
            }
            right++;
        }
        return maxlen;
    }
};