class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector < vector<int> > re;
    if (root) {
      vector<TreeNode *> nodes;
      nodes.push_back(root);
      int start = 0;
      bool odd = true;
      while (start != nodes.size()) {
        int size = nodes.size();
        for (int i = start; i < size; i++) {
          TreeNode *node = nodes[i];
          if (node->left) {
            nodes.push_back(node->left);
          }
          if (node->right) {
            nodes.push_back(node->right);
          }
        }
        vector<int> value;
        if (odd) {
          for (int i = start; i < size; i++) {
            value.push_back(nodes[i]->val);
          }
        } else {
          for (int i = size - 1; i >= start; i--) {
            value.push_back(nodes[i]->val);
          }
        }
        odd = !odd;
        re.push_back(value);
        start = size;
      }
    }
    return re;
  }
};
