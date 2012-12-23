class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL) {
      return head;
    }
    ListNode *tail = head;
    while (k > 0) {
      k--;
      tail = tail->next;
      if (tail == NULL) {
        tail = head;
      }
    }
    ListNode *rotate = head;
    while (tail->next) {
      tail = tail->next;
      rotate = rotate->next;
    }
    if (rotate->next == NULL) {
      return head;
    }
    tail->next = head;
    head = rotate->next;
    rotate->next = NULL;
    return head;
  }
};
