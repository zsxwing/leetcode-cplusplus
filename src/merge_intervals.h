bool cmp(const Interval &x, const Interval &y) {
  if (x.start == y.start) {
    return x.end < y.end;
  }
  return x.start < y.start;
}

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> re;
    if (intervals.size() == 0) {
      return re;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    Interval pre = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
      if (pre.end >= intervals[i].start) {
        pre.end = max(pre.end, intervals[i].end);
      } else {
        re.push_back(pre);
        pre = intervals[i];
      }
    }
    re.push_back(pre);
    return re;
  }
};

