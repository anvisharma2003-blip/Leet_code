#include <string>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> lastPos(256, -1);
        
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            unsigned char ch = s[right];

            if (lastPos[ch] >= left) {
                left = lastPos[ch] + 1;
            }

            lastPos[ch] = right;

            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }

        return maxLen;
    }
};