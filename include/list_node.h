#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <stddef.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) :
      val(x), next(NULL) {
  }
};

#endif // LIST_NODE_H
