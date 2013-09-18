class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    if (haystack == NULL || needle == NULL) {
      return NULL;
    }
    if (*needle == '\0') {
      return haystack;
    }
    while (*haystack) {
      char *p = haystack;
      char *q = needle;
      while (*p && *q && *p == *q) {
        p++;
        q++;
      }
      if (*q) {
        if (*p) {
          haystack++;
        } else {
          break;
        }
      } else {
        return haystack;
      }
    }
    return NULL;
  }
};
