class Solution {
private:
  void makeFour(vector<int> *four, int a, int b, int c, int d) {
    four->push_back(a);
    four->push_back(b);
    four->push_back(c);
    four->push_back(d);
  }

  void twoSum(int target, int a, int b, vector<int> &num, int start,
      vector<vector<int> > *re) {
    int i = start;
    int j = num.size() - 1;
    while (i < j) {
      if (num[i] + num[j] < target) {
        i++;
      } else if (num[i] + num[j] > target) {
        j--;
      } else {
        vector<int> four;
        makeFour(&four, a, b, num[i], num[j]);
        re->push_back(four);
        while (i < j && num[i] == num[i + 1]) {
          i++;
        }
        i++;
        while (i < j && num[j] == num[j - 1]) {
          j--;
        }
        j--;
      }
    }
  }

public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    vector < vector<int> > re;
    for (int i = 0; i < num.size(); i++) {
      if (i != 0 && num[i] == num[i - 1]) {
        continue;
      }
      int a = num[i];
      for (int j = i + 1; j < num.size(); j++) {
        if (j != i + 1 && num[j] == num[j - 1]) {
          continue;
        }
        int b = num[j];
        twoSum(target - a - b, a, b, num, j + 1, &re);
      }
    }
    return re;
  }
};
