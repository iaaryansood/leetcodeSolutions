class Solution {
public:
    void backtracking(vector<string> &answer,string curr_str,int leftCount,int rightCount,int n)
    {
        if(curr_str.size() == 2 * n)
        {
            answer.push_back(curr_str);
            return;
        }
        else
        {
            if(leftCount < n)
            {
                backtracking(answer,curr_str+'(',leftCount+1,rightCount,n);
            }
            if(leftCount > rightCount)
            {
                backtracking(answer,curr_str+')',leftCount,rightCount+1,n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        // optimised approach backtracking
        vector<string> answer;
        string curr_str="";
        backtracking(answer,curr_str,0,0,n);
        return answer;
    }
};