class Solution {
private:
  bool isOnTheSameLine(Point &p1, Point &p2, Point &p3) {
    return (p3.y - p2.y) * (p2.x - p1.x) == (p3.x - p2.x) * (p2.y - p1.y);
  }
public:
  int maxPoints(vector<Point> &points) {
    vector<pair<Point, Point>> lines;
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        if (points[i].x != points[j].x || points[i].y != points[j].y) {
          lines.push_back(make_pair(points[i], points[j]));
        }
      }
    }
    if (lines.size() == 0) {
      return points.size();
    }
    vector<int> counts(lines.size(), 0);
    for (int i = 0; i < lines.size(); i++) {
      pair<Point, Point> line = lines[i];
      for (int j = 0; j < points.size(); j++) {
        if (isOnTheSameLine(line.first, line.second, points[j])) {
          counts[i]++;
        }
      }
    }
    return *max_element(counts.begin(), counts.end());
  }
};
