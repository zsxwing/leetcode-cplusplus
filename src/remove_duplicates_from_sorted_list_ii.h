class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL) {
      return NULL;
    }
    bool removed = false;
    ListNode **p = &(head);
    while ((*p)->next) {
      if ((*p)->val == (*p)->next->val) {
        *p = (*p)->next;
        removed = true;
      } else if (removed) {
        *p = (*p)->next;
        removed = false;
      } else {
        p = &((*p)->next);
      }
    }
    if (removed) {
      *p = (*p)->next;
    }
    return head;
  }
};
