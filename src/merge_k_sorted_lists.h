class ListNodeCmp {
public:
  bool operator()(ListNode * x, ListNode * y) {
    return y->val < x->val;
  }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, ListNodeCmp> heap;
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i]) {
        heap.push(lists[i]);
      }
    }
    ListNode *mergeList = NULL;
    ListNode **pre = &mergeList;
    while (!heap.empty()) {
      ListNode *node = heap.top();
      heap.pop();
      *pre = node;
      pre = &(node->next);
      if (node->next) {
        heap.push(node->next);
      }
    }
    *pre = NULL;
    return mergeList;
  }
};
