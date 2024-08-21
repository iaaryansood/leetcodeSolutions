class Solution {
public:
    int characterReplacement(string s, int k) { 
        int maxlen=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int> map(26,0);
            int maxf=0;
            for(int j=i;j<s.size();j++)
            {
                int len=j-i+1;
                map[s[j] - 'A']++;
                maxf=max(maxf,map[s[j] - 'A']);
                int changes=len - maxf;
                if(changes <= k)
                {
                    maxlen=max(maxlen,len);
                }
                else
                {
                    break;
                }
            }
        }
        return maxlen;
    }
};