#include<stdio.h>
#include<limits.h>

void printArray(int *A, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d, ", A[i]);
	}
	printf("\n");
}

void merge(int *A, int p, int q, int r) {

	int i, j;

	/* find lengths of the two halves */
	int n1 = q - p + 1;
	int n2 = r - q;

	/* make two arrays corresponding to the left and right half */
	int L[n1+1];
	int R[n2+1];

	/* fill the arrays with the two halves */
	for(i = 0; i < n1; i++) {
		L[i] = A[p+i];
	}
	for(j = 0; j < n2; j++) {
		R[j] = A[q+1+j];
	}

	/* introduce a sentinel in the last position */
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	/* Merge */
	i = 0;
	j = 0;
	for(int k = p; k <= r; k++) {
		if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int *A, int p, int r) {
	if(p < r) {
		/* find middle */
		int q = (p+r)/2;

		/* merge sort the two inputs */
		mergeSort(A, p,	q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}


int main() {
	/* Obtain input from stdin, first number is length */
	int n;
	scanf("%d", &n);
	
	int A[n];

	for(int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	/* merge sort */
	mergeSort(A, 0, n - 1);

	printArray(A, n);
}
