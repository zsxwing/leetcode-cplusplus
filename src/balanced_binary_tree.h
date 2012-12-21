
class Solution {

private:
    int getBalancedTreeHeight(TreeNode *root) {
        if (root == NULL) return 0;
	int leftHeight = getBalancedTreeHeight(root->left);
	int rightHeight = getBalancedTreeHeight(root->right);
	if (leftHeight >= 0 && rightHeight >= 0) {
		if (leftHeight + 1 == rightHeight) {
			return rightHeight + 1;
		}
		else if (leftHeight == rightHeight + 1 || leftHeight == rightHeight){
			return leftHeight + 1;
		}
	}
	return -1;
    }

public:
    bool isBalanced(TreeNode *root) {
        return getBalancedTreeHeight(root) >= 0; 
    }
};

