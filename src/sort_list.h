class Solution {
private:
  ListNode *merge(ListNode *h1, ListNode *h2) {
    ListNode *head = NULL;
    ListNode **prefix = &head;
    while (h1 || h2) {
      if (h2 == NULL || (h1 && h1->val < h2->val)) {
        *prefix = h1;
        prefix = &(h1->next);
        h1 = h1->next;
      } else {
        *prefix = h2;
        prefix = &(h2->next);
        h2 = h2->next;
      }
    }
    return head;
  }

  ListNode *sortList(ListNode *head, int start, int end, ListNode * &tail) {
    if (start == end) {
      tail = head;
      return NULL;
    }
    if (end - start == 1) {
      tail = head->next;
      head->next = NULL;
      return head;
    }
    int mid = start + (end - start) / 2;
    ListNode *left = sortList(head, start, mid, tail);
    ListNode *right = sortList(tail, mid, end, tail);
    return merge(left, right);
  }

  int len(ListNode *head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }

public:
  ListNode *sortList(ListNode *head) {
    ListNode *tail;
    return sortList(head, 0, len(head), tail);
  }
};
