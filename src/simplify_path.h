#include <string>
using namespace std;

static const int DOT = 1;
static const int DOUBLE_DOT = 2;
static const int NORMAL = 3;
static const int SLASH = 4;

class Solution {
public:
  string simplifyPath(string path) {
    string simplify;
    int state = SLASH;
    int lastSlashPos = -1;
    for (int i = 0; i < path.size(); i++) {
      char c = path[i];
      switch (state) {
      case DOT:
        if (c == '.') {
          state = DOUBLE_DOT;
        } else if (c == '/') {
          state = SLASH;
          lastSlashPos = i;
        } else {
          state = NORMAL;
        }
        break;
      case DOUBLE_DOT:
        if (c == '/') {
          int pos = simplify.rfind('/');
          if (pos == string::npos) {
            simplify = "";
          } else {
            simplify = simplify.substr(0, pos);
          }
          state = SLASH;
          lastSlashPos = i;
        } else {
          state = NORMAL;
        }
        break;
      case NORMAL:
        if (c == '/') {
          simplify += "/";
          simplify += path.substr(lastSlashPos + 1, i - lastSlashPos - 1);
          state = SLASH;
          lastSlashPos = i;
        } else {
          state = NORMAL;
        }
        break;
      case SLASH:
        if (c == '/') {
          state = SLASH;
          lastSlashPos = i;
        } else if (c == '.') {
          state = DOT;
        } else {
          state = NORMAL;
        }
        break;
      }
    }
    switch (state) {
    case DOT:
      break;
    case DOUBLE_DOT: {
      int pos = simplify.rfind('/');
      if (pos == string::npos) {
        simplify = "";
      } else {
        simplify = simplify.substr(0, pos);
      }
    }
      break;
    case NORMAL:
      simplify += "/";
      simplify += path.substr(lastSlashPos + 1);
      break;
    case SLASH:
      break;
    }
    return simplify == "" ? "/" : simplify;
  }
};
