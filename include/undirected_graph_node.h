#ifndef UNDIRECTED_GRAPH_NODE_H
#define UNDIRECTED_GRAPH_NODE_H

#include <vector>
using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) :
      label(x) {
  }
  ;
};

#endif // UNDIRECTED_GRAPH_NODE_H
