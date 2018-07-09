#include<stdio.h>
#include<stdlib.h>

struct heap {
        int *A;
        int length;
        int heapSize;
};

void printArray(struct heap *h) {
	for(int i = 0; i < h->length; i++) {
		printf("%d, ", h->A[i]);
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

void swap (struct heap *h, int i, int j) {
        int tmp = h->A[i];
        h->A[i] = h->A[j];
        h->A[j] = tmp;
}
        

void maxHeapify(struct heap *h, int i) {
        int largest;
        int l = left(i);
        int r = right(i);

        if(l < h->heapSize && h->A[l] > h->A[i]) {
                largest = l;
        } else largest = i;

        if (r < h->heapSize && h->A[r] > h->A[largest]) {
                largest = r;
        }
    
        if(largest != i) {
                swap (h, i, largest);
                maxHeapify(h, largest);
        }
}

void buildMaxHeap(struct heap *h) {
        for(int i = h->heapSize/2-1; i >= 0; i--) {
                maxHeapify(h, i);
        }
}

void heapsort(struct heap *h) {
        buildMaxHeap(h);
        for(int i = h->heapSize-1; i > 0; i--) {
                swap(h, 0, i);
                h->heapSize--;
                maxHeapify(h, 0);
        }
}

int main() {
        int A[] = {16,14,10,8,7,9,3,2,4,1};

        struct heap h;
        h.heapSize = 10;
        h.length = 10;
        h.A = A;

        heapsort(&h);
        printArray(&h);
}
