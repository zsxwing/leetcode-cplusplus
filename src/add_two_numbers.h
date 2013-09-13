class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL;
    ListNode **tail = &head;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
      int v1 = l1 ? l1->val : 0;
      int v2 = l2 ? l2->val : 0;
      int v = v1 + v2 + carry;
      carry = v / 10;
      *tail = new ListNode(v % 10);
      tail = &(*tail)->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    if (carry) {
      *tail = new ListNode(carry);
    }
    return head;
  }
};
