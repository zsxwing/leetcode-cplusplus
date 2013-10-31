class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        while (fast != head) {
          fast = fast->next;
          head = head->next;
        }
        return fast;
      }
    }
    return NULL;
  }
};
