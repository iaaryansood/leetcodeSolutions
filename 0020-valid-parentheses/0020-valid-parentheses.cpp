class Solution {
public:
    bool isValid(string s) {
        int i=0;
        int n=s.size();
        stack<char> st;
        while(i < n)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;

                else if(s[i] == ')' && st.top() != '(') return false;

                else if(s[i] == '}' && st.top() != '{') return false;

                else if(s[i] == ']' && st.top() != '[') return false;
                st.pop();
            }
            i++;
        }
        return st.empty();
    }
};