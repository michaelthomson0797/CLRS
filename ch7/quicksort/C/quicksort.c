#include <stdio.h>

void swap(int *A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
}

int partition(int *A, int p, int r) {
        int x = A[r];
        int i = p-1;
        for(int j = p; j <= r-1; j++) {
                if(A[j] <= x) {
                        i++;
                        swap(A, i, j);
                }
        }
        swap(A, i+1, r);
        return i+1;
}

void quicksort(int *A, int p, int r) {
        if (p < r) {
                int q = partition(A, p, r);
                quicksort(A, p, q-1);
                quicksort(A, q+1, r);
        }
}

void printArray(int *A, int n) {
        for(int i = 0; i < n; i++) {
                printf("%d, ", A[i]);
        }
        printf("\n");
}
                
int main() {
        int A[] = {2,8,7,1,3,5,6,4};

        quicksort(A, 0, 7);

        printArray(A, 8);
}
