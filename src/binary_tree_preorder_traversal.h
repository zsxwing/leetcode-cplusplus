class Solution {
private:
  void preorderTraversal(TreeNode *root, vector<int> &preorder) {
    if (root == NULL) {
      return;
    }
    preorder.push_back(root->val);
    preorderTraversal(root->left, preorder);
    preorderTraversal(root->right, preorder);
  }

public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> preorder;
    preorderTraversal(root, preorder);
    return preorder;
  }
public:
  vector<int> preorderTraversalWithIterative(TreeNode *root) {
    vector<int> preorder;
    vector<TreeNode *> stack;
    stack.push_back(root);
    while (!stack.empty()) {
      TreeNode *p = stack.back();
      stack.pop_back();
      while (p) {
        preorder.push_back(p->val);
        stack.push_back(p->right);
        p = p->left;
      }
    }
    return preorder;
  }
};
