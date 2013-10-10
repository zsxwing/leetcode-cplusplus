class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *p = head;
    while (n > 1) {
      p = p->next;
      n--;
    }
    ListNode **pre = &head;
    while (p->next) {
      p = p->next;
      pre = &((*pre)->next);
    }
    *pre = (*pre)->next;
    return head;
  }
};
