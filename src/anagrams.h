class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    vector < string > re;
    unordered_map < string, vector<string> > dict;
    for (auto i = strs.begin(); i != strs.end(); ++i) {
      string key = *i;
      sort(key.begin(), key.end());
      dict[key].push_back(*i);
    }
    for (auto i = dict.begin(); i != dict.end(); ++i) {
      if (i->second.size() > 1) {
        re.insert(re.end(), i->second.begin(), i->second.end());
      }
    }
    return re;
  }
};
