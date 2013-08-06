class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> nums(num.begin(), num.end());

    int longest = 0;
    for (int i = 0; i < num.size(); i++) {
      unordered_set<int>::iterator iter;
      int count = 1;

      int n = num[i] - 1;
      iter = nums.find(n);
      while (iter != nums.end()) {
        count++;
        n--;
        nums.erase(iter);
        iter = nums.find(n);
      }

      n = num[i] + 1;
      iter = nums.find(n);
      while (iter != nums.end()) {
        count++;
        n++;
        nums.erase(iter);
        iter = nums.find(n);
      }

      longest = max(count, longest);
    }
    return longest;
  }
};
