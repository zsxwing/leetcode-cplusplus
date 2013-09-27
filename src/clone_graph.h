class Solution {
private:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node,
      unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &nodes) {
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    nodes[node] = newNode;
    for (int i = 0; i < node->neighbors.size(); i++) {
      UndirectedGraphNode *neighbor = node->neighbors[i];
      auto iter = nodes.find(neighbor);
      UndirectedGraphNode *newNeighbor;
      if (iter == nodes.end()) {
        newNeighbor = cloneGraph(neighbor, nodes);
      } else {
        newNeighbor = iter->second;
      }
      newNode->neighbors.push_back(newNeighbor);
    }
    return newNode;
  }

public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) {
      return NULL;
    }
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodes;
    return cloneGraph(node, nodes);
  }
};
