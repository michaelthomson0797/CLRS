#include<stdio.h>

void printArray(int *A, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d, ", A[i]);
	}
	printf("\n");
}

int parent(int i) {
        return i/2;
}

int left(int i) {
        return 2*i+1;
}

int right(int i) {
        return 2*i+2;
}

void swap (int *A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
}
        

void maxHeapify(int *A, int i, int heapSize) {
        int largest;
        int l = left(i);
        int r = right(i);

        if(l < heapSize && A[l] > A[i]) {
                largest = l;
        } else largest = i;

        if (r < heapSize && A[r] > A[largest]) {
                largest = r;
        }
    
        if(largest != i) {
                swap (A, i, largest);
                maxHeapify(A, largest, heapSize);
        }
}

void buildMaxHeap(int *A, int heapSize) {
        for(int i = heapSize/2-1; i >= 0; i--) {
                maxHeapify(A, i, heapSize);
        }
}

void heapsort(int *A, int heapSize) {
        buildMaxHeap(A, heapSize);
        for(int i = heapSize-1; i > 0; i--) {
                swap(A, 0, i);
                printArray(A, 10);
                heapSize = heapSize - 1;
                maxHeapify(A, 0, heapSize);
        }
}

int main() {
        int A[] = {16,14,10,8,7,9,3,2,4,1};
        heapsort(A, 10);
        printArray(A, 10);
}
