class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode *p = head;
    head = NULL;
    while (p) {
      ListNode **pre = &head;
      while (*pre) {
        if ((*pre)->val <= p->val) { // stable sort
          pre = &((*pre)->next);
        } else {
          break;
        }
      }
      ListNode *temp = p->next;
      p->next = *pre;
      *pre = p;
      p = temp;
    }
    return head;
  }
};
