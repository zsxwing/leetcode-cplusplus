class Solution {
private:
  void search(vector<int> &candidates, int index, int target,
      vector<int> &combination, vector<vector<int> > &re) {
    if (target == 0) {
      re.push_back(combination);
      return;
    }

    if (index == candidates.size() || target < candidates[index]) {
      return;
    }

    int candidate = candidates[index];
    for (int i = 0; i <= target / candidate; i++) {
      search(candidates, index + 1, target - i * candidate, combination, re);
      combination.push_back(candidate);
    }
    combination.erase(
        combination.begin() + combination.size() - target / candidate - 1,
        combination.end());
  }

public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector < vector<int> > re;
    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    unique(candidates.begin(), candidates.end());
    search(candidates, 0, target, combination, re);
    return re;
  }
};
