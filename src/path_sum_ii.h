class Solution {
private:
  void pathSum(TreeNode *root, int sum, vector<int> & path,
      vector<vector<int> > & res) {
    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
      if (root->val == sum) {
        res.push_back(path);
      }
      path.pop_back();
      return;
    }
    if (root->left) {
      pathSum(root->left, sum - root->val, path, res);
    }
    if (root->right) {
      pathSum(root->right, sum - root->val, path, res);
    }
    path.pop_back();
  }

public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector < vector<int> > res;
    vector<int> path;
    if (root) {
      pathSum(root, sum, path, res);
    }
    return res;
  }
};
