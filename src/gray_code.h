#include <vector>
using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> answer;
    answer.push_back(0);
    int power = 1;
    while (n--) {
      int size = answer.size();
      for (int i = size - 1; i >= 0; --i) {
        answer.push_back(power + answer[i]);
      }
      power <<= 1;
    }
    return answer;
  }
};
