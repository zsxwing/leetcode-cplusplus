class Solution {

  void connectWithRecursion(TreeLinkNode *root) {
    if (root == NULL || root->left == NULL) {
      return;
    }
    root->left->next = root->right;
    if (root->next) {
      root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
  }

  void connectWithConstantSpace(TreeLinkNode *root) {
    TreeLinkNode *leftMost = root;
    while (leftMost) {
      TreeLinkNode *cross = leftMost;
      while (cross->left) {
        cross->left->next = cross->right;
        if (cross->next) {
          cross->right->next = cross->next->left;
          cross = cross->next;
        } else {
          break;
        }
      }
      leftMost = leftMost->left;
    }
  }

public:
  void connect(TreeLinkNode *root) {
    connectWithConstantSpace(root);
  }
};
