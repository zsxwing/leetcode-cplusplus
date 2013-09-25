class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL;
    ListNode **pre = &head;
    while (l1 && l2) {
      if (l1->val > l2->val) {
        *pre = l2;
        l2 = l2->next;
      } else {
        *pre = l1;
        l1 = l1->next;
      }
      pre = &((*pre)->next);
    }
    if (l1) {
      *pre = l1;
    }
    if (l2) {
      *pre = l2;
    }
    return head;
  }
};
