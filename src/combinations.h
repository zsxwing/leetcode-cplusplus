class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector < vector<int> > re;
    if (n == 0 || n < k) {
      return re;
    }
    vector<int> flag;
    flag.assign(n, 0);
    fill(flag.begin() + (n - k), flag.end(), 1);
    do {
      vector<int> ans;
      for (int i = 0; i < n; i++) {
        if (flag[i]) {
          ans.push_back(i + 1);
        }
      }
      re.push_back(ans);
    } while (next_permutation(flag.begin(), flag.end()));
    return re;
  }
};
