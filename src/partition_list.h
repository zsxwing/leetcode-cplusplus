class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *lessHead = NULL;
    ListNode **lessTail = &lessHead;
    ListNode *greaterHead = NULL;
    ListNode **greaterTail = &greaterHead;
    ListNode *p = head;
    while (p) {
      if (p->val < x) {
        *lessTail = p;
        lessTail = &p->next;
      } else {
        *greaterTail = p;
        greaterTail = &p->next;
      }
      p = p->next;
    }
    *lessTail = greaterHead;
    *greaterTail = NULL;
    return lessHead;
  }
};
