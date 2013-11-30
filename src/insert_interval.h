class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> re;
    int i;
    for (i = 0; i < intervals.size(); i++) {
      Interval interval = intervals[i];
      if (interval.end < newInterval.start) {
        re.push_back(interval);
      } else if (interval.start > newInterval.end) {
        break;
      } else {
        newInterval.start = min(newInterval.start, interval.start);
        newInterval.end = max(newInterval.end, interval.end);
      }
    }
    re.push_back(newInterval);
    for (; i < intervals.size(); i++) {
      re.push_back(intervals[i]);
    }
    return re;
  }
};
