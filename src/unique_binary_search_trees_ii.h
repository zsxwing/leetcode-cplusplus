class Solution {
private:
  void generateTrees(int start, int end, vector<TreeNode *> *re) {
    if (start > end) {
      re->push_back(NULL);
      return;
    }

    for (int i = start; i <= end; i++) {
      vector<TreeNode *> leftSubtrees;
      generateTrees(start, i - 1, &leftSubtrees);
      vector<TreeNode *> rightSubtrees;
      generateTrees(i + 1, end, &rightSubtrees);
      for (int l = 0; l < leftSubtrees.size(); l++) {
        for (int r = 0; r < rightSubtrees.size(); r++) {
          TreeNode *root = new TreeNode(i);
          root->left = leftSubtrees[l];
          root->right = rightSubtrees[r];
          re->push_back(root);
        }
      }
    }
  }

public:
  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> re;
    generateTrees(1, n, &re);
    return re;
  }
};
