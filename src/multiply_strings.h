class Solution {
private:
  void stringToVector(string &strNum, vector<int> *intNum) {
    for(int i=0;i<strNum.size();i++) {
      intNum->push_back(strNum[i] - '0');
    }
  }

  void vectorToString(vector<int> &intNum, string *strNum) {
    for(int i=0;i<intNum.size();i++) {
      *strNum += ('0' + intNum[i]);
    }
  }

  void multiply(vector<int> &num, int digit, vector<int> *result) {
    int carry = 0;
    for(int i=0;i<num.size();i++) {
      int temp = carry + digit * num[i];
      carry = temp / 10;
      result->push_back(temp % 10);
    }
    if(carry) {
      result->push_back(carry);
    }
  }

  void addWithOffset(vector<int> &large, vector<int> &small, int offset, vector<int> *result) {
    int index = 0;
    int carry = 0;
    while(index < small.size() || index < large.size() + offset) {
      int largeDigit = index - offset >= 0 && index < large.size() + offset ? large[index - offset] : 0;
      int smallDigit = index < small.size() ? small[index] : 0;
      int temp = carry + largeDigit + smallDigit;
      carry = temp / 10;
      result->push_back(temp % 10);
      index++;
    }
    if(carry) {
      result->push_back(carry);
    }
  }

public:
  string multiply(string num1, string num2) {
    vector<int> large;
    vector<int> small;
    if(num1.size() >= num2.size()) {
      stringToVector(num1, &large);
      stringToVector(num2, &small);
    }
    else {
      stringToVector(num2, &large);
      stringToVector(num1, &small);
    }
    reverse(large.begin(), large.end());
    reverse(small.begin(), small.end());
    vector<int> result;
    result.push_back(0);
    for(int i=0;i<small.size();i++) {
      vector<int> temp;
      if(small[i]) {
        multiply(large, small[i], &temp);
        vector<int> addResult;
        addWithOffset(temp, result, i, &addResult);
        result = addResult;
      }
    }
    reverse(result.begin(), result.end());
    string re;
    vectorToString(result, &re);
    return re;
  }
};
