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
      while (left < right && !isalnum(s[left])) {
        left++;
      }
      while (left < right && !isalnum(s[right])) {
        right--;
      }
      if (left >= right) {
        break;
      }
      if (tolower(s[left++]) != tolower(s[right--])) {
        return false;
      }
    }
    return true;
  }
};
