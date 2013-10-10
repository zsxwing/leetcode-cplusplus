class Solution {
public:
    void sortColors(int A[], int n) {
        int zero = -1;
        int one = -1;
        for(int i = 0; i<n; i++) {
            if(A[i] == 0) {
                A[i] = A[++zero];
                A[zero] = 0;
                one = max(zero, one);
            }
            if(A[i] == 1) {
                A[i] = A[++one];
                A[one] = 1;
            }
        }
    }
};
