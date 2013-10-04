class Solution {
private:
  RandomListNode *getNewNode(
      unordered_map<RandomListNode *, RandomListNode *> &nodes,
      RandomListNode *oldNode) {
    RandomListNode *newNode;
    auto iter = nodes.find(oldNode);
    if (iter == nodes.end()) {
      newNode = new RandomListNode(oldNode->label);
      nodes[oldNode] = newNode;
    } else {
      newNode = iter->second;
    }
    return newNode;
  }

public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *newHead = NULL;
    RandomListNode *p = head;
    unordered_map<RandomListNode *, RandomListNode *> nodes;
    while (p) {
      RandomListNode *newP = getNewNode(nodes, p);
      if (newHead == NULL) {
        newHead = newP;
      }
      if (p->next) {
        newP->next = getNewNode(nodes, p->next);
      }
      if (p->random) {
        newP->random = getNewNode(nodes, p->random);
      }
      p = p->next;
    }
    return newHead;
  }
};
