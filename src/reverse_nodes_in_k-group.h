class Solution {
private:
  ListNode **reverseGroup(ListNode **head, ListNode *groupBegin,
      ListNode *groupEnd) {
    ListNode *prev = groupBegin;
    ListNode *next = groupBegin->next;
    while (next != groupEnd) {
      ListNode *temp = next->next;
      next->next = prev;
      prev = next;
      next = temp;
    }
    *head = prev;
    return &(groupBegin->next);
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k <= 1) {
      return head;
    }
    ListNode **prevGroupNext = &head;
    ListNode *groupBegin = head;
    ListNode *groupEnd = head;
    do {
      int count = 0;
      while (groupEnd && count < k) {
        groupEnd = groupEnd->next;
        count++;
      }
      if (count == k) {
        prevGroupNext = reverseGroup(prevGroupNext, groupBegin, groupEnd);
        groupBegin = groupEnd;
      }
    } while (groupEnd);
    *prevGroupNext = groupBegin;
    return head;
  }
};
