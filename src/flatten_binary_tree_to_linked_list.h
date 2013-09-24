class Solution {
private:
  TreeNode* to(TreeNode *root) {
    if (root == NULL) {
      return NULL;
    }
    TreeNode *tail = root;
    TreeNode *right = root->right;
    if (root->left) {
      tail = to(root->left);
      root->right = root->left;
      root->left = NULL;
      tail->right = right;
    }
    if (right) {
      tail = to(root->right);
    }
    return tail;
  }

public:
  void flatten(TreeNode *root) {
    to(root);
  }
};
