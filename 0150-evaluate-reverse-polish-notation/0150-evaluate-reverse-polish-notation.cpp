class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i=0;
        stack<int> s;
        while(i < tokens.size())
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int first=s.top();
                s.pop();
                int second=s.top();
                s.pop();
                if(tokens[i] == "+")
                {
                    int ans=second+first;
                    s.push(ans);
                }
                else if(tokens[i] == "-")
                {
                    int ans=second-first;
                    s.push(ans);
                }
                else if(tokens[i] == "*")
                {
                    int ans=second*first;
                    s.push(ans);
                }
                else
                {
                    int ans=second/first;
                    s.push(ans);
                }
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
            i++;
        }
        return s.top();
    }
};