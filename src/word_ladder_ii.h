class Solution {
public:
  vector<vector<string> > findLadders(string start, string end,
      unordered_set<string> &dict) {
    vector < vector<string> > res;
    if (start == end) {
      res.push_back(vector < string > (1, start));
      return res;
    }

    dict.insert(start);

    vector < string > nodes;
    unordered_map<string, int> indeces;
    for (auto i = dict.begin(); i != dict.end(); ++i) {
      indeces[*i] = nodes.size();
      nodes.push_back(*i);
    }
    vector < vector<int> > adj(nodes.size(), vector<int>());
    for (int i = 0; i < nodes.size(); i++) {
      string temp = nodes[i];
      for (int j = 0; j < temp.size(); j++) {
        for (char c = 'a'; c <= 'z'; c++) {
          if (c != temp[j]) {
            temp[j] = c;
            auto iter = indeces.find(temp);
            if (iter != indeces.end()) {
              adj[i].push_back(iter->second);
            }
            temp[j] = nodes[i][j];
          }
        }
      }
    }

    int startIndex = indeces[start];
    int endIndex = indeces[end];
    vector<int> q;
    q.push_back(startIndex);
    vector<int> path;
    path.push_back(-1);

    int begin = 0;
    bool find = false;
    unordered_set<int> searched;
    searched.insert(startIndex);
    while (!find && begin < q.size()) {
      int tail = q.size();
      for (int i = begin; i < tail; i++) {
        int nodeIndex = q[i];
        for (auto iter = adj[nodeIndex].begin(); iter != adj[nodeIndex].end();
            ++iter) {
          if (*iter == endIndex) {
            find = true;
            vector < string > temp;
            temp.push_back(end);
            temp.push_back(nodes[nodeIndex]);
            int last = path[i];
            while (last >= 0) {
              temp.push_back(nodes[q[last]]);
              last = path[last];
            }
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            break;
          } else if (searched.find(*iter) == searched.end()) {
            q.push_back(*iter);
            path.push_back(i);
          }
        }
      }
      searched.insert(q.begin() + tail, q.end());
      begin = tail;
    }
    return res;
  }
};

