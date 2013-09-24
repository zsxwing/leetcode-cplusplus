class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode **pre = &head;
    ListNode *p = head;
    while (p && p->next) {
      ListNode *second = p->next;
      *pre = second;
      p->next = second->next;
      second->next = p;
      pre = &(p->next);
      p = p->next;
    }
    *pre = p;
    return head;
  }
};
