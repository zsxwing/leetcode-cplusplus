class IndexComparator {
private:
  vector<int> *numbers;
public:
  IndexComparator(vector<int> *numbers) :
      numbers(numbers) {
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
    sort(indices, indices + numbers.size(), IndexComparator(&numbers));
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
    int lowIndex = min(indices[low], indices[high]) + 1; // not zero-based
    int highIndex = max(indices[low], indices[high]) + 1; // not zero-based
    delete[] indices;
    int result[] = { lowIndex, highIndex };
    return vector<int>(result, result + 2);
  }
};
