class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int lastPos[CHAR_MAX + 1];
    fill(lastPos, lastPos + (CHAR_MAX + 1), -1);
    int maxSubstringLen = 0;
    int substringBegin = 0;
    for (int i = 0; i < s.size(); i++) {
      substringBegin = max(substringBegin, lastPos[s[i]] + 1);
      lastPos[s[i]] = i;
      maxSubstringLen = max(maxSubstringLen, i - substringBegin + 1);
    }
    return maxSubstringLen;
  }
};
