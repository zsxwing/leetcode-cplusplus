class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    if (start == end) {
      return 1;
    }
    unordered_set < string > used;
    int level = 0;
    int begin = 0;
    vector < string > q;
    q.push_back(start);
    used.insert(start);
    while (begin < q.size()) {
      int tail = q.size();
      for (int index = begin; index < tail; index++) {
        string s = q[index];
        string t = s;
        for (int i = 0; i < s.size(); i++) {
          char c = s[i];
          for (char j = 'a'; j <= 'z'; j++) {
            t[i] = j;
            if (t == end) {
              return level + 2;
            }
            if (dict.find(t) != dict.end() && used.find(t) == used.end()) {
              q.push_back(t);
              used.insert(t);
            }
            t[i] = c;
          }
        }
      }
      level++;
      begin = tail;
    }
    return 0;
  }
};
