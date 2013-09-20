class Solution {
private:
  int getBalancedTreeHeight(TreeNode *root) {
    if (root == NULL)
      return 0;
    int leftHeight = getBalancedTreeHeight(root->left);
    int rightHeight = getBalancedTreeHeight(root->right);
    if (leftHeight >= 0 && rightHeight >= 0) {
      if (abs(leftHeight - rightHeight) <= 1) {
        return max(leftHeight, rightHeight) + 1;
      }
    }
    return -1;
  }

public:
  bool isBalanced(TreeNode *root) {
    return getBalancedTreeHeight(root) >= 0;
  }
};

