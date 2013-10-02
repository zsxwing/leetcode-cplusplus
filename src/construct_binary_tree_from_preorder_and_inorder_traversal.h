class Solution {
private:
  TreeNode *buildTree(vector<int> &preorder, int preBegin,
      unordered_map<int, int> &inorder, int inBegin, int len) {
    if (len == 0) {
      return NULL;
    }
    int rootValue = preorder[preBegin];
    TreeNode *root = new TreeNode(rootValue);
    int i = inorder[root->val];
    int leftLen = i - inBegin;
    int rightLen = len - leftLen - 1;
    root->left = buildTree(preorder, preBegin + 1, inorder, inBegin, leftLen);
    root->right = buildTree(preorder, preBegin + 1 + leftLen, inorder, i + 1,
        rightLen);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> inorderNodes;
    for (int i = 0; i < inorder.size(); i++) {
      inorderNodes[inorder[i]] = i;
    }
    return buildTree(preorder, 0, inorderNodes, 0, inorder.size());
  }
};
