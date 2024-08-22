class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int left=0,right=0;
        int minlen=INT_MAX;
        int startIndex=-1;

        for(int i=0;i<t.size();i++)
        {
            hash[t[i]]++;
        }

        int count=0;
        while(right < s.size())
        {
            if(hash[s[right]] > 0)
            {
                count++;
            }
            hash[s[right]]--;
            while(count == t.size())
            {
                if(right-left+1 < minlen)
                {
                    minlen=right-left+1;
                    startIndex=left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0)
                {
                    count--;
                }
                left++;
            }
            right++;
        }
       if(startIndex == -1)
       {
            return "";
       }
       return s.substr(startIndex,right - left + 1);
    }
};