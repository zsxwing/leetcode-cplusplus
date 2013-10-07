class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) {
      return NULL;
    }
    RandomListNode *p = head;
    while (p) {
      RandomListNode *newP = new RandomListNode(p->label);
      newP->next = p->next;
      newP->random = p->random;
      p->next = newP;
      p = newP->next;
    }
    p = head;
    RandomListNode *newHead = p->next;
    while (p) {
      RandomListNode * newP = p->next;
      if (newP->random) {
        newP->random = newP->random->next;
      }
      p = newP->next;
    }
    p = head;
    while (p) {
      RandomListNode *newP = p->next;
      p->next = newP->next;
      if (newP->next) {
        newP->next = newP->next->next;
      }
      p = p->next;
    }
    return newHead;
  }
};
