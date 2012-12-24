class Solution {

public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *lessTail = NULL;
    ListNode *lessHead = NULL;
    ListNode *greaterHead = NULL;
    ListNode *greaterTail = NULL;
    ListNode *next = head;
    while (next) {
      if (next->val < x) {
        if (lessTail) {
          lessTail->next = next;
        } else {
          lessHead = next;
        }
        lessTail = next;
      } else {
        if (greaterTail) {
          greaterTail->next = next;
        } else {
          greaterHead = next;
        }
        greaterTail = next;
      }
      next = next->next;
    }
    if (lessHead == NULL) {
      lessHead = greaterHead;
    } else {
      lessTail->next = greaterHead;
    }
    if (greaterTail) {
      greaterTail->next = NULL;
    }
    return lessHead;
  }
};
