class Solution {
private:
  bool isEqual(unordered_map<string, int> &m1, unordered_map<string, int> &m2) {
    if (m1.size() != m2.size()) {
      return false;
    }
    for (auto i1 = m1.begin(); i1 != m1.end(); ++i1) {
      auto i2 = m2.find(i1->first);
      if (i1->second != i2->second) {
        return false;
      }
    }
    return true;
  }
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> ans;
    if (L.empty() || L[0].size() == 0) {
      return ans;
    }

    unordered_map<string, int> wordCount;
    for (int i = 0; i < L.size(); i++) {
      auto iterWordCount = wordCount.find(L[i]);
      if (iterWordCount == wordCount.end()) {
        wordCount[L[i]] = 1;
      } else {
        ++iterWordCount->second;
      }
    }

    int wordLen = L[0].size();
    int substringLen = wordLen * L.size();
    unordered_map<string, int> temp;
    for (int i = 0; i + substringLen <= S.size(); i++) {
      temp.clear();
      bool skip = false;
      for (int j = 0; j < substringLen; j += wordLen) {
        string word = S.substr(i + j, wordLen);
        auto wordIter = wordCount.find(word);
        if (wordIter != wordCount.end()) {
          auto tempIter = temp.find(word);
          if (tempIter == temp.end()) {
            temp[word] = 1;
          } else if (tempIter->second >= wordIter->second) {
            skip = true;
            break;
          } else {
            ++tempIter->second;
          }
        } else {
          skip = true;
          break;
        }
      }
      if (!skip && isEqual(temp, wordCount)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
