class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector < vector<int> > re;
    re.push_back(vector<int>());
    for (int i = 0; i < S.size(); i++) {
      int len = re.size();
      while (len--) {
        re.push_back(re[len]);
        re.back().push_back(S[i]);
      }
    }
    return re;
  }
};
