class Solution {
public:
    bool isPalindrome(string s) {
        vector<string> temp;
        vector<char> ans;
        for(int i=0;i<s.size();i++)
        {
            char temp=s[i];
            if((temp >= 97 && temp <= 122) || (temp >= 65 && temp <= 90) || (temp >= 48 && temp <= 57))
            {
                if(temp >= 65 && temp <= 90)
                {
                    // cout<<temp+'a' - 'A';
                    temp=tolower(temp);
                    cout<<temp;
                    ans.push_back(temp);
                }
                else
                {
                    cout<<temp;
                    ans.push_back(temp);
                }
            }
        }
        int start=0,end=ans.size()-1;
        
        while(start <= end)
        {
            if(ans[start++] != ans[end--])
            {
                return false;
            }
        }
        return true;
    }
};