class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector < vector<int> > re;
    if (root) {
      int start = 0;
      vector<TreeNode *> level;
      level.push_back(root);
      while (start != level.size()) {
        int size = level.size();
        vector<int> value;
        for (; start < size; start++) {
          TreeNode *node = level[start];
          value.push_back(node->val);
          if (node->left) {
            level.push_back(node->left);
          }
          if (node->right) {
            level.push_back(node->right);
          }
        }
        re.push_back(value);
      }
    }
    return re;
  }
};
