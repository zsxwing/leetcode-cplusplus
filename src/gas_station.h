class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int start = 0;
    while (start < gas.size()) {
      int end = start;
      int rest = 0;
      do {
        rest += gas[end] - cost[end];
        end = (end + 1) % gas.size();
        if (rest < 0) {
          if (end <= start) {
            return -1;
          }
          break;
        }
      } while (end != start);
      if (end == start) {
        return start;
      }
      start = end;
    }
    return -1;
  }
};
