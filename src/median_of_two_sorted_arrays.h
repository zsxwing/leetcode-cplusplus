class Solution {
private:
  double findMedianSortedArrays(int A[], int aLen, int left, int right, int B[],
      int bLen) {
    if (left > right) {
      return findMedianSortedArrays(B, bLen, max(0, (aLen + bLen) / 2 - aLen),
          min(bLen - 1, (aLen + bLen) / 2), A, aLen);
    }

    int i = (left + right) / 2;
    int j = (aLen + bLen) / 2 - i - 1;
    if (j >= 0 && A[i] < B[j]) {
      return findMedianSortedArrays(A, aLen, i + 1, right, B, bLen);
    }
    if (j < bLen - 1 && A[i] > B[j + 1]) {
      return findMedianSortedArrays(A, aLen, left, i - 1, B, bLen);
    }

    if ((aLen + bLen) & 1) {
      return A[i];
    }

    int prev;
    if (i == 0) {
      prev = B[j];
    } else if (j < 0) {
      prev = A[i - 1];
    } else {
      prev = max(A[i - 1], B[j]);
    }
    return (prev + A[i]) / 2.0;
  }

public:
  double findMedianSortedArrays(int A[], int aLen, int B[], int bLen) {
    return findMedianSortedArrays(A, aLen, max(0, (aLen + bLen) / 2 - bLen),
        min(aLen - 1, (aLen + bLen) / 2), B, bLen);
  }
};
