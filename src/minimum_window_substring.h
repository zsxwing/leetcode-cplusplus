class Solution {
public:
  string minWindow(string S, string T) {
    int t_count[256] = { 0 };
    for (int i = 0; i < T.size(); i++) {
      t_count[T[i]]++;
    }
    int s_count[256] = { 0 };
    int i = 0;
    for (i = 0; i < S.size(); i++) {
      s_count[S[i]]++;
      bool find = true;
      for (int j = 0; j < 256; j++) {
        if (s_count[j] < t_count[j]) {
          find = false;
          break;
        }
      }
      if (find) {
        break;
      }
    }
    if (i == S.size()) {
      return "";
    }
    int window_start = 0;
    int window_end = i;

    int min_window_start = window_start;
    int min_window_end = window_end;
    while (window_start < S.size()) {
      char c = S[window_start];
      s_count[c]--;
      window_start++;
      if (s_count[c] < t_count[c]) {
        window_end++;
        while (window_end < S.size()) {
          char end_c = S[window_end];
          s_count[end_c]++;
          if (end_c == c) {
            break;
          }
          window_end++;
        }
        if (window_end == S.size()) {
          break;
        }
      }
      if (window_end - window_start < min_window_end - min_window_start) {
        min_window_start = window_start;
        min_window_end = window_end;
      }
    }
    return S.substr(min_window_start, min_window_end - min_window_start + 1);
  }
};
