class Solution {
private:
  void search(vector<int> &num, vector<int> &count, int index, int target,
      vector<int> *combination, vector<vector<int> > *re) {
    if (target == 0) {
      re->push_back(*combination);
      return;
    }
    if (index == num.size()) {
      return;
    }

    for (int i = 0; i <= count[index] && i * num[index] <= target; i++) {
      search(num, count, index + 1, target - i * num[index], combination, re);
      combination->push_back(num[index]);
    }
    for (int i = 0; i <= count[index] && i * num[index] <= target; i++) {
      combination->pop_back();
    }
  }

public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector < vector<int> > re;
    if (num.size() == 0) {
      return re;
    }

    sort(num.begin(), num.end());
    vector<int> nums;
    vector<int> counts;
    int count = 1;
    int i = 1;
    for (; i < num.size(); i++) {
      if (num[i] == num[i - 1]) {
        count++;
      } else {
        nums.push_back(num[i - 1]);
        counts.push_back(count);
        count = 1;
      }
    }
    nums.push_back(num[i - 1]);
    counts.push_back(count);

    vector<int> combination;
    search(nums, counts, 0, target, &combination, &re);
    return re;
  }
};
