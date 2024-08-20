#include<unordered_map>
class Solution {
public:
    // bool checkInclusion(string s1, string s2) {
    //     unordered_map<char,int> map,map2;
    //     for(int i=0;i<s1.length();i++)
    //     {
    //         map[s1[i]]++;
    //     }
    //     int i=0,window=s1.length();
    //     while(i < window && i < s2.length())
    //     {
    //         map2[s2[i]]++;
    //         i++;
    //     }
    //     if(map == map2)
    //     {
    //         return true;
    //     }
    //     while(i < s2.length())
    //     {
    //         map2[s2[i]]++;
    //         map2[s2[i-window]]--;
    //         if(map == map2)
    //         {
    //             return true;
    //         }
    //         i++;
    //     }
    //     return false;
    // }
    bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> map, map2;
    for (char c : s1) {
        map[c]++;
    }

    int i = 0, window = s1.length();
    while (i < window && i < s2.length()) {
        map2[s2[i]]++;
        i++;
    }

    if (map == map2) {
        return true;
    }

    while (i < s2.length()) {
        map2[s2[i]]++;
        map2[s2[i - window]]--; // Corrected line
        if (map2[s2[i - window]] == 0) {
            map2.erase(s2[i - window]); // Remove the character from map2
        }
        i++;
        if (map == map2) {
            return true;
        }
    }

    return false;
}

};