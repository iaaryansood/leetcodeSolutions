#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.size();
        int s2Len = s2.size();

        if (s1Len > s2Len) return false;  // If s1 is longer than s2, impossible to have a permutation.

        unordered_map<char, int> s1Map, s2Map;

        // Count frequencies of each character in s1
        for (char c : s1) {
            s1Map[c]++;
        }

        // Initialize the frequency map for the first window in s2
        for (int i = 0; i < s1Len; i++) {
            s2Map[s2[i]]++;
        }

        // Check if the first window matches s1's character frequency
        if (s1Map == s2Map) return true;

        // Slide the window over s2
        for (int i = s1Len; i < s2Len; i++) {
            // Add the new character in the window
            char newChar = s2[i];
            s2Map[newChar]++;
            
            // Remove the old character from the window
            char oldChar = s2[i - s1Len];
            if (s2Map[oldChar] == 1) {
                s2Map.erase(oldChar);  // Remove entry if count is zero
            } else {
                s2Map[oldChar]--;
            }

            // Check if the current window matches s1's character frequency
            if (s1Map == s2Map) return true;
        }

        return false;  // No permutation found
    }
};
