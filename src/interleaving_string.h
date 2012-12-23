#include <string>
using namespace std;

class Solution {

private:
  bool isInterleave(const char* s1, int l1, const char* s2, int l2,
      const char* s3, int l3) {
    if (l1 == 0) {
      return l2 == l3 && strncmp(s2, s3, l2) == 0;
    }
    if (l2 == 0) {
      return l1 == l3 && strncmp(s1, s3, l1) == 0;
    }
    if (l3 == 0) {
      return false;
    }
    return (s1[l1 - 1] == s3[l3 - 1]
        && isInterleave(s1, l1 - 1, s2, l2, s3, l3 - 1))
        || (s2[l2 - 1] == s3[l3 - 1]
            && isInterleave(s1, l1, s2, l2 - 1, s3, l3 - 1));
  }

public:
  bool isInterleave(string s1, string s2, string s3) {
    return isInterleave(s1.c_str(), s1.size(), s2.c_str(), s2.size(),
        s3.c_str(), s3.size());
  }
};
