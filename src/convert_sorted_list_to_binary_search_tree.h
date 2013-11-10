class Solution {
private:
  TreeNode *sortedListToBST(ListNode *&head, int start, int end) {
    if (start > end) {
      return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(0);
    root->left = sortedListToBST(head, start, mid - 1);
    root->val = head->val;
    head = head->next;
    root->right = sortedListToBST(head, mid + 1, end);
    return root;
  }

public:
  TreeNode *sortedListToBST(ListNode *head) {
    int len = 0;
    ListNode *p = head;
    while (p) {
      len++;
      p = p->next;
    }
    return sortedListToBST(head, 0, len - 1);
  }
};
