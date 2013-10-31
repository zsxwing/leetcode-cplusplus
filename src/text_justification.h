class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    vector < string > lines;
    if (words.empty()) {
      return lines;
    }
    int startWordIndex = 0;
    int currentWordLength = 0;
    for (int i = 0; i < words.size(); i++) {
      if (currentWordLength + (i - startWordIndex) + words[i].size() > L) {
        string line = words[startWordIndex];
        int wordCount = i - startWordIndex;
        if (wordCount != 1) {
          int spaceLength = L - currentWordLength;
          int gapAvgLength = spaceLength / (wordCount - 1);
          int j = 0;
          for (j = 0; j < spaceLength - gapAvgLength * (wordCount - 1); j++) {
            line.append(gapAvgLength + 1, ' ');
            line += words[startWordIndex + 1 + j];
          }
          for (; j < wordCount - 1; j++) {
            line.append(gapAvgLength, ' ');
            line += words[startWordIndex + 1 + j];
          }
        }
        line.append(L - line.size(), ' ');
        lines.push_back(line);
        currentWordLength = words[i].size();
        startWordIndex = i;
      } else {
        currentWordLength += words[i].size();
      }
    }
    // The last line
    string line;
    line += words[startWordIndex];
    for (int i = startWordIndex + 1; i < words.size(); i++) {
      line += ' ';
      line += words[i];
    }
    line.append(L - line.size(), ' ');
    lines.push_back(line);
    return lines;
  }
};
