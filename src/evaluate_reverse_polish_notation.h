class Solution {
private:
  void fetchNumsFromStack(vector<int> &stack, int &num1, int &num2) {
    num2 = stack.back();
    stack.pop_back();
    num1 = stack.back();
    stack.pop_back();
  }
public:
  int evalRPN(vector<string> &tokens) {
    vector<int> stack;
    int num1, num2;
    for(int i= 0;i < tokens.size(); i++) {
      string& token = tokens[i];
      if(token == "+") {
        fetchNumsFromStack(stack, num1, num2);
        stack.push_back(num1 + num2);
      } else if(token == "-") {
        fetchNumsFromStack(stack, num1, num2);
        stack.push_back(num1 - num2);
      } else if(token == "*") {
        fetchNumsFromStack(stack, num1, num2);
        stack.push_back(num1 * num2);
      } else if(token == "/") {
        fetchNumsFromStack(stack, num1, num2);
        stack.push_back(num1 / num2);
      } else {
        stack.push_back(atoi(token.c_str()));
      }
    }
    return stack.back();
  }
};
