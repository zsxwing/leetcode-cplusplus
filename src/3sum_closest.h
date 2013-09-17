class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int closestSum = num[0] + num[1] + num[2];
    for (int i = 0; i + 2 < num.size(); i++) {
      if (i != 0 && num[i] == num[i - 1]) {
        continue;
      }
      int twoSum = target - num[i];
      int begin = i + 1;
      int end = num.size() - 1;
      while (begin < end) {
        int sum = num[begin] + num[end];
        if (abs(twoSum - sum) < abs(target - closestSum)) {
          closestSum = sum + num[i];
        }
        if (sum < twoSum) {
          begin++;
        } else if (sum > twoSum) {
          end--;
        } else {
          return target;
        }
      }
    }
    return closestSum;
  }
};
