class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = A[0];
        int maxSum = A[0];
        for(int i = 1; i < n; i++) {
            sum = max(sum + A[i], A[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
