class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *leftMost = root;
    while (leftMost) {
      TreeLinkNode *cross = leftMost;
      leftMost = NULL;
      TreeLinkNode **preNode = &leftMost;
      while (cross) {
        if (cross->left) {
          *preNode = cross->left;
          preNode = &(cross->left->next);
        }
        if (cross->right) {
          *preNode = cross->right;
          preNode = &(cross->right->next);
        }
        cross = cross->next;
      }
    }
  }
};
