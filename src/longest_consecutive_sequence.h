class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> nums(num.begin(), num.end());
    int longest = 0;
    for (int i = 0; i < num.size(); i++) {
      int x = num[i] - 1;
      auto iter = nums.find(x);
      while (iter != nums.end()) {
        nums.erase(iter);
        x--;
        iter = nums.find(x);
      }

      int y = num[i] + 1;
      iter = nums.find(y);
      while (iter != nums.end()) {
        nums.erase(iter);
        y++;
        iter = nums.find(y);
      }
      longest = max(y - x - 1, longest);
    }
    return longest;
  }
};
