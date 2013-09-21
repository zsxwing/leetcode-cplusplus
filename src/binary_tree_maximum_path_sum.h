class Solution {
private:
  int maxPathSum(TreeNode *root, int *maxPathSumWithRoot) {
    int left = 0, right = 0;
    int leftMax, rightMax;
    if (root->left) {
      leftMax = maxPathSum(root->left, &left);
      left = left < 0 ? 0 : left;
    }
    if (root->right) {
      rightMax = maxPathSum(root->right, &right);
      right = right < 0 ? 0 : right;
    }

    *maxPathSumWithRoot = max(left + root->val, right + root->val);

    int maxPath = left + right + root->val;
    if (root->left) {
      maxPath = max(maxPath, leftMax);
    }
    if (root->right) {
      maxPath = max(maxPath, rightMax);
    }
    return maxPath;
  }

public:
  int maxPathSum(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int dummy;
    return maxPathSum(root, &dummy);
  }
};
