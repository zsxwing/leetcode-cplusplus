#ifndef INTERVAL_H
#define INTERVAL_H

struct Interval {
  int start;
  int end;
  Interval() :
      start(0), end(0) {
  }
  Interval(int s, int e) :
      start(s), end(e) {
  }
};

#endif // INTERVAL_H
