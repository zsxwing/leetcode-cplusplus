class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> nodes;
    TreeNode *p = root;
    while (p) {
      if (p->left == NULL) {
        nodes.push_back(p->val);
        p = p->right;
      } else {
        TreeNode *temp = p->left;
        while (temp->right != NULL && temp->right != p) {
          temp = temp->right;
        }
        if (temp->right == NULL) {
          temp->right = p;
          p = p->left;
        } else {
          nodes.push_back(p->val);
          temp->right = NULL;
          p = p->right;
        }
      }
    }
    return nodes;
  }
};
