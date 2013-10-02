class Solution {
private:
  TreeNode *buildTree(unordered_map<int, int> &inorder, int inBegin,
      vector<int> &postorder, int postBegin, int len) {
    if (len == 0) {
      return NULL;
    }
    TreeNode *root = new TreeNode(postorder[postBegin + len - 1]);
    int i = inorder[root->val];
    int leftLen = i - inBegin;
    int rightLen = len - leftLen - 1;
    root->left = buildTree(inorder, inBegin, postorder, postBegin, leftLen);
    root->right = buildTree(inorder, i + 1, postorder, postBegin + leftLen,
        rightLen);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int, int> inorderNodes;
    for (int i = 0; i < inorder.size(); i++) {
      inorderNodes[inorder[i]] = i;
    }
    return buildTree(inorderNodes, 0, postorder, 0, postorder.size());
  }
};
