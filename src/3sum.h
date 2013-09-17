class Solution {
private:
  void makeTriple(vector<int> *triple, int a, int b, int c) {
    triple->push_back(a);
    triple->push_back(b);
    triple->push_back(c);
  }

  void twoSum(int a, vector<int> &num, int start, vector<vector<int> > *re) {
    int i = start;
    int j = num.size() - 1;
    while (i < j) {
      if (num[i] + num[j] < -a) {
        i++;
      } else if (num[i] + num[j] > -a) {
        j--;
      } else {
        vector<int> triple;
        makeTriple(&triple, a, num[i], num[j]);
        re->push_back(triple);
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
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector < vector<int> > re;
    for (int i = 0; i < num.size(); i++) {
      if (i != 0 && num[i] == num[i - 1]) {
        continue;
      }
      int a = num[i];
      twoSum(a, num, i + 1, &re);
    }
    return re;
  }
};
