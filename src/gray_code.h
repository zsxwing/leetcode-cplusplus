class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> re;
    for (int i = 0; i < 1 << n; i++) {
      re.push_back(i ^ (i >> 1));
    }
    return re;
  }
};
