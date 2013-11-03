class Solution {
private:
  ListNode *reverse(ListNode *head) {
    ListNode *pre = NULL;
    ListNode *p = head;
    while (p) {
      ListNode *temp = p->next;
      p->next = pre;
      pre = p;
      p = temp;
    }
    return pre;
  }

  void split(ListNode *head, ListNode **l1, ListNode **l2) {
    *l1 = head;
    *l2 = NULL;
    if (head == NULL || head->next == NULL) {
      return;
    }
    ListNode *slow = head;
    ListNode *fast = head->next->next;
    while (fast) {
      slow = slow->next;
      if (fast->next == NULL) {
        break;
      }
      fast = fast->next->next;
    }
    *l2 = slow->next;
    slow->next = NULL;
  }

  void zip(ListNode *l1, ListNode *l2) {
    while (l2) {
      ListNode *temp = l1->next;
      l1->next = l2;
      l1 = temp;
      temp = l2->next;
      l2->next = l1;
      l2 = temp;
    }
  }

public:
  void reorderList(ListNode *head) {
    ListNode *l1, *l2;
    split(head, &l1, &l2);
    l2 = reverse(l2);
    zip(l1, l2);
  }
};
