#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
  const char *searchTheEndChar(const char *p, const char *end) {
    char c = *end;
    while (p < end && *p != c) {
      p++;
    }
    return p == end ? NULL : p;
  }

public:
  int lengthOfLongestSubstring(string s) {
    const char *p = s.c_str();
    int max_substring_length = 0;
    const char* substring_begin = p;
    while (*p) {
      const char *repeated_char = searchTheEndChar(substring_begin, p);
      if (repeated_char) {
        // We find a repeated char.
        max_substring_length = max(max_substring_length,
            (int) (p - substring_begin));
        substring_begin = repeated_char + 1;
      }
      p++;
    }
    return max(max_substring_length, (int) (p - substring_begin));
  }
};
