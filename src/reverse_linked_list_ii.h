class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (m <= 0 || m >= n) {
      return head;
    }
    int count = n - m + 1;
    m--;
    ListNode **prefix = &head;
    while (m > 0) {
      m--;
      prefix = &((*prefix)->next);
    }
    ListNode *pre = NULL;
    ListNode *p = *prefix;
    ListNode *reverseTail = p;
    while (count > 0) {
      ListNode *temp = p->next;
      p->next = pre;
      pre = p;
      p = temp;
      count--;
    }
    *prefix = pre;
    if (reverseTail) {
      reverseTail->next = p;
    }
    return head;
  }
};
