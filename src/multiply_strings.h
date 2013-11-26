class Solution {
private:
  void stringToVector(string &strNum, vector<int> *intNum) {
    for (int i = strNum.size() - 1; i >= 0; i--) {
      intNum->push_back(strNum[i] - '0');
    }
  }

  void vectorToString(vector<int> &intNum, string *strNum) {
    int i = intNum.size() - 1;
    for (; i >= 0; i--) {
      if (intNum[i]) {
        break;
      }
    }
    for (; i >= 0; i--) {
      *strNum += ('0' + intNum[i]);
    }
    if (strNum->size() == 0) {
      *strNum += '0';
    }
  }

  void multiply(vector<int> &num, int digit, vector<int> *result) {
    int carry = 0;
    for (int i = 0; i < num.size(); i++) {
      int temp = carry + digit * num[i];
      carry = temp / 10;
      result->push_back(temp % 10);
    }
    if (carry) {
      result->push_back(carry);
    }
  }

  void addWithOffset(vector<int> &large, vector<int> &small, int offset,
      vector<int> *result) {
    int index = 0;
    int carry = 0;
    while (index < small.size() || index < large.size() + offset) {
      int largeDigit =
          index - offset >= 0 && index < large.size() + offset ?
              large[index - offset] : 0;
      int smallDigit = index < small.size() ? small[index] : 0;
      int temp = carry + largeDigit + smallDigit;
      carry = temp / 10;
      result->push_back(temp % 10);
      index++;
    }
    if (carry) {
      result->push_back(carry);
    }
  }

public:
  string multiply(string num1, string num2) {
    vector<int> intNum1;
    vector<int> intNum2;
    stringToVector(num1, &intNum1);
    stringToVector(num2, &intNum2);

    vector<int> result;
    result.push_back(0);
    for (int i = 0; i < intNum2.size(); i++) {
      vector<int> temp;
      if (intNum2[i]) {
        multiply(intNum1, intNum2[i], &temp);
        vector<int> addResult;
        addWithOffset(temp, result, i, &addResult);
        result = addResult;
      }
    }

    string re;
    vectorToString(result, &re);
    return re;
  }
};
