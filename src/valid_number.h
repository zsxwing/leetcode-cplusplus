enum {
  START = 0,
  DECIMAL = 2,
  FRACTION = 3,
  E = 4,
  SIGNAL = 5,
  E_SIGNAL = 6,
  E_DECIMAL = 7,
  DOT = 8
};

class Solution {
private:
  bool isOnlySpaceLeft(const char *s) {
    while (isspace(*s)) {
      s++;
    }
    return *s == '\0';
  }

public:
  bool isNumber(const char *s) {
    bool hasDigit = false;
    int status = START;
    while (*s) {
      char c = *s;
      switch (status) {
      case START:
        if (isspace(c)) {
          // do nothing
        } else if (isdigit(c)) {
          status = DECIMAL;
          hasDigit = true;
        } else if (c == '.') {
          status = DOT;
        } else if (c == '+' || c == '-') {
          status = SIGNAL;
        } else {
          return false;
        }
        break;
      case DECIMAL:
        if (isdigit(c)) {
          // do nothing
        } else if (c == '.') {
          status = DOT;
        } else if (c == 'E' || c == 'e') {
          status = E;
        } else {
          return isOnlySpaceLeft(s);
        }
        break;
      case SIGNAL:
        if (isdigit(c)) {
          status = DECIMAL;
          hasDigit = true;
        } else if (c == '.') {
          status = DOT;
        } else {
          return false;
        }
        break;
      case DOT:
        if (isdigit(c)) {
          status = FRACTION;
          hasDigit = true;
        } else if (c == 'E' || c == 'e') {
          status = E;
        } else {
          return hasDigit && isOnlySpaceLeft(s);
        }
        break;
      case FRACTION:
        if (isdigit(c)) {
          // do nothing
        } else if (c == 'E' || c == 'e') {
          status = E;
        } else {
          return isOnlySpaceLeft(s);
        }
        break;
      case E:
        if (isdigit(c)) {
          status = E_DECIMAL;
        } else if (c == '+' || c == '-') {
          status = E_SIGNAL;
        } else {
          return false;
        }
        break;
      case E_DECIMAL:
        if (isdigit(c)) {
          status = E_DECIMAL;
        } else {
          return isOnlySpaceLeft(s);
        }
        break;
      case E_SIGNAL:
        if (isdigit(c)) {
          status = E_DECIMAL;
        } else {
          return false;
        }
        break;
      }
      s++;
    }
    return hasDigit && isOnlySpaceLeft(s)
        && (status == DOT || status == DECIMAL || status == FRACTION
            || status == E_DECIMAL);
  }
};
