#ifndef RANDOM_LIST_NODE_H
#define RANDOM_LIST_NODE_H

#include <stddef.h>

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) :
      label(x), next(NULL), random(NULL) {
  }
};

#endif // RANDOM_LIST_NODE_H
