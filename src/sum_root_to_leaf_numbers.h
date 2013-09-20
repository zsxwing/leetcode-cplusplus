class Solution {
private:
  int sumNumbers(TreeNode *root, int num) {
    if (root == NULL) {
      return 0;
    }
    num = num * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
      return num;
    }
    return sumNumbers(root->left, num) + sumNumbers(root->right, num);
  }

public:
  int sumNumbers(TreeNode *root) {
    return sumNumbers(root, 0);
  }
};
