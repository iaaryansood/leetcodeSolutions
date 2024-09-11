class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> map;
        for(int i=0;i<wordList.size();i++)
        {
            map[wordList[i]]++;
        }

        queue<pair<string,int>> q;
        q.push(pair<string,int>(beginWord,1));
        map.erase(beginWord);

        while(!q.empty())
        {
            string temp=q.front().first;
            int depth=q.front().second;
            q.pop();
            
            if(temp == endWord)
            {
                return depth;
            }
            for(int i=0;i<temp.size();i++)
            {
                char original=temp[i];
                for(char ch='a';ch <= 'z';ch++)
                {
                    temp[i]=ch;
                    if(map.find(temp) != map.end())
                    {
                        q.push(pair<string,int>(temp,depth+1));
                        map.erase(temp);
                    }   
                }
                temp[i]=original;
            }
        }
        return 0;
    }

};