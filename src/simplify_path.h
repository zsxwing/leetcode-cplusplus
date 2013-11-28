enum {
  DOT = 0, DOUBLE_DOT, NORMAL, SLASH
};

class Solution {
public:
  string simplifyPath(string path) {
    string simplify;
    int state = SLASH;
    for (int i = 1; i < path.size(); i++) {
      char c = path[i];
      switch (state) {
      case DOT:
        if (c == '.') {
          state = DOUBLE_DOT;
        } else if (c == '/') {
          state = SLASH;
        } else {
          simplify += '/';
          simplify += '.';
          simplify += c;
          state = NORMAL;
        }
        break;
      case DOUBLE_DOT:
        if (c == '/') {
          int pos = simplify.rfind('/');
          if (pos != string::npos) {
            simplify = simplify.substr(0, pos);
          }
          state = SLASH;
        } else {
          simplify += '/';
          simplify += '.';
          simplify += '.';
          simplify += c;
          state = NORMAL;
        }
        break;
      case NORMAL:
        if (c == '/') {
          state = SLASH;
        } else {
          simplify += c;
        }
        break;
      case SLASH:
        if (c == '/') {
        } else if (c == '.') {
          state = DOT;
        } else {
          state = NORMAL;
          simplify += '/';
          simplify += c;
        }
        break;
      }
    }
    if (state == DOUBLE_DOT) {
      int pos = simplify.rfind('/');
      if (pos != string::npos) {
        simplify = simplify.substr(0, pos);
      }
    }
    return simplify == "" ? "/" : simplify;
  }
};
