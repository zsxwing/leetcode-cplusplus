class Solution {
private:
  bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (left == NULL || right == NULL) {
      return left == right;
    }
    if (left->val == right->val) {
      return isSymmetric(left->left, right->right)
          && isSymmetric(left->right, right->left);
    }
    return false;
  }
public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
      return true;
    }
    return isSymmetric(root->left, root->right);
  }
};

class SolutionWithIterative {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
      return true;
    }
    queue<TreeNode *> lefts;
    queue<TreeNode *> rights;
    lefts.push(root->left);
    rights.push(root->right);
    while (!lefts.empty() && !rights.empty()) {
      TreeNode *left = lefts.front();
      lefts.pop();
      TreeNode *right = rights.front();
      rights.pop();
      if (left == NULL && right == NULL) {
        continue;
      }
      if (left == NULL || right == NULL) {
        return false;
      }
      if (left->val != right->val) {
        return false;
      }
      lefts.push(left->left);
      lefts.push(left->right);
      rights.push(right->right);
      rights.push(right->left);
    }
    return lefts.empty() && rights.empty();
  }
};
