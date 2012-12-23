class Solution {

public:
  int lengthOfLastWord(const char *s) {
    const char *start_of_word = s;
    const char *end_of_word = s;
    bool is_last_char_space = false;
    while (*s) {
      if (*s == ' ') {
        if (!is_last_char_space) {
          end_of_word = s;
          is_last_char_space = true;
        }
      } else {
        if (is_last_char_space) {
          start_of_word = s;
          is_last_char_space = false;
        }
      }
      s++;
    }
    if (!is_last_char_space) {
      end_of_word = s;
    }
    return end_of_word - start_of_word;
  }
};
