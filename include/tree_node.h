#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <stddef.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
  }
};

#endif // TREE_NODE_H
