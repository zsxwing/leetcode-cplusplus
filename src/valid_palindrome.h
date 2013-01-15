#include <stdlib.h>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int length = s.size();
    int left = 0;
    int right = length - 1;
    while (left < right) {
      while (left < length && !isalnum(s[left])) {
        left++;
      }
      if (left >= length) {
        break;
      }
      while (right >= 0 && !isalnum(s[right])) {
        right--;
      }
      if (right < 0) {
        break;
      }
      if (tolower(s[left++]) != tolower(s[right--])) {
        return false;
      }
    }
    return true;
  }
};
