class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    if (root->left && root->right) {
      return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    if (root->left) {
      return minDepth(root->left) + 1;
    }
    if (root->right) {
      return minDepth(root->right) + 1;
    }
    return 1;
  }
};
