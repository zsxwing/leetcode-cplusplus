class Solution {
private:
  inline void visit(TreeNode *p, TreeNode * &prev, TreeNode *&first,
      TreeNode *&second) {
    if (prev && prev->val > p->val) {
      if (first) {
        second = p;
      } else {
        first = prev;
        second = p;
      }
    }
    prev = p;
  }

public:
  void recoverTree(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *p = root;
    TreeNode *prev = NULL;
    while (p) {
      if (p->left == NULL) {
        visit(p, prev, first, second);
        p = p->right;
      } else {
        TreeNode *temp = p->left;
        while (temp->right && temp->right != p) {
          temp = temp->right;
        }
        if (temp->right == NULL) {
          temp->right = p;
          p = p->left;
        } else {
          visit(p, prev, first, second);
          temp->right = NULL;
          p = p->right;
        }
      }
    }
    swap(first->val, second->val);
  }
};
