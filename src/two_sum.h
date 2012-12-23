#include <vector>
#include <algorithm>
using namespace std;

class IndexComparator {
private:
  vector<int> *numbers;
public:
  IndexComparator(vector<int> &numbers) :
      numbers(&numbers) {
  }
  bool operator()(int i, int j) {
    return (*numbers)[i] < (*numbers)[j];
  }
};

class Solution {
private:
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int *indices = new int[numbers.size()];
    for (int i = 0; i < numbers.size(); i++) {
      indices[i] = i;
    }
    sort(indices, indices + numbers.size(), IndexComparator(numbers));
    int low = 0;
    int high = numbers.size() - 1;
    while (low < high) {
      int sum = numbers[indices[low]] + numbers[indices[high]];
      if (sum < target) {
        low++;
      } else if (sum > target) {
        high--;
      } else {
        break;
      }
    }
    int lowIndex = indices[low];
    int highIndex = indices[high];
    delete[] indices;
    vector<int> result;
    if (lowIndex < highIndex) {
      result.push_back(lowIndex + 1);
      result.push_back(highIndex + 1);
    } else {
      result.push_back(highIndex + 1);
      result.push_back(lowIndex + 1);
    }
    return result;
  }
};
