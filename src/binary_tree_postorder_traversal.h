class Solution {
private:
  void postorderTraversal(TreeNode *root, vector<int> &postorder) {
    if (root == NULL) {
      return;
    }
    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->val);
  }
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> postorder;
    postorderTraversal(root, postorder);
    return postorder;
  }
public:
  vector<int> postorderTraversalWithIterative(TreeNode *root) {
    vector<int> postorder;
    if (root == NULL) {
      return postorder;
    }
    vector<TreeNode *> stack;
    stack.push_back(root);
    TreeNode *prev = NULL;
    while (!stack.empty()) {
      TreeNode *p = stack.back();
      if (prev == NULL || prev->left == p || prev->right == p) {
        if (p->left) {
          stack.push_back(p->left);
        } else if (p->right) {
          stack.push_back(p->right);
        }
      } else if (p->left == prev) {
        if (p->right) {
          stack.push_back(p->right);
        }
      } else {
        postorder.push_back(p->val);
        stack.pop_back();
      }
      prev = p;
    }
    return postorder;
  }
};
