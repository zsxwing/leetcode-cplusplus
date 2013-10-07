class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector < vector<int> > re;
    if (root != NULL) {
      vector<TreeNode *> nodes;
      nodes.push_back(root);
      int start = 0;
      while (start != nodes.size()) {
        nodes.push_back(NULL);
        int size = nodes.size() - 1;
        for (; start < size; start++) {
          TreeNode *node = nodes[start];
          if (node->right) {
            nodes.push_back(node->right);
          }
          if (node->left) {
            nodes.push_back(node->left);
          }
        }
        start++;
      }
      vector<int> value;
      for (int i = nodes.size() - 2; i >= 0; i--) {
        TreeNode *node = nodes[i];
        if (node) {
          value.push_back(node->val);
        } else {
          re.push_back(value);
          value.clear();
        }
      }
      re.push_back(value);
    }
    return re;
  }
};
