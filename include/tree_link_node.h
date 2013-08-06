#ifndef TREE_LINK_NODE_H
#define TREE_LINK_NODE_H

#include <stdlib.h>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) :
      val(x), left(NULL), right(NULL), next(NULL) {
  }
};

#endif // TREE_LINK_NODE_H
