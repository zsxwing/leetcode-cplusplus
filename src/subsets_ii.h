class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector < vector<int> > re;
    re.push_back(vector<int>());
    int last;
    for (int i = 0; i < S.size(); i++) {
      int start = 0;
      if (i != 0 && S[i] == S[i - 1]) {
        start = last;
      }
      last = re.size();
      for (int j = start; j < last; j++) {
        re.push_back(re[j]);
        re.back().push_back(S[i]);
      }
    }
    return re;
  }
};
