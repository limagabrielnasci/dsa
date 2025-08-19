#include <stdio.h>

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    if (matrixSize == 0) return 0;
    int n = matrixSize;

    long long lo = matrix[0][0];
    long long hi = matrix[n - 1][n - 1];

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;

        int count = 0;
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && (long long)matrix[i][j] > mid) j--;
            count += (j + 1);
        }

        if (count < k) lo = mid + 1;
        else hi = mid;
    }
    return (int)lo;
}

int main() {
    return 0;
}
