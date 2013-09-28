class Solution {
private:
  bool isValidBST(TreeNode *root, int *min, int *max) {
    *min = root->val;
    *max = root->val;
    if (root->left) {
      int leftMin, leftMax;
      if (!isValidBST(root->left, &leftMin, &leftMax)) {
        return false;
      }
      if (leftMax >= root->val) {
        return false;
      }
      *min = leftMin;
    }
    if (root->right) {
      int rightMin, rightMax;
      if (!isValidBST(root->right, &rightMin, &rightMax)) {
        return false;
      }
      if (rightMin <= root->val) {
        return false;
      }
      *max = rightMax;
    }
    return true;
  }

public:
  bool isValidBST(TreeNode *root) {
    if (root == NULL) {
      return true;
    }
    int dummy;
    return isValidBST(root, &dummy, &dummy);
  }
};
