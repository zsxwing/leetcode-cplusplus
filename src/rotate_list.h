class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL) {
      return head;
    }
    ListNode *tail = head;
    int listSize = 0;
    while (k > 0) {
      k--;
      listSize++;
      tail = tail->next;
      if (tail == NULL) {
        // Here we get the list size.
        // We can use k % listSize to reduce the repeated search.
        tail = head;
        k = k % listSize;
        while (k > 0) {
          k--;
          // We do not need to check if tail is NULL, since 0 <= k < listSize.
          tail = tail->next;
        }
        break;
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
