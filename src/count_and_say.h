class Solution {
public:
  string countAndSay(int n) {
    string re = "1";
    for (int i = 1; i < n; i++) {
      int count = 1;
      ostringstream temp;
      for (int j = 1; j < re.size(); j++) {
        if (re[j] == re[j - 1]) {
          count++;
        } else {
          temp << count;
          temp << re[j - 1];
          count = 1;
        }
      }
      temp << count;
      temp << re[re.size() - 1];
      re = temp.str();
    }
    return re;
  }
};
