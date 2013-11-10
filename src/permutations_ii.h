class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    sort(num.begin(), num.end());
    vector < vector<int> > re;
    do {
      re.push_back(num);
    } while (next_permutation(num.begin(), num.end()));
    return re;
  }
};
