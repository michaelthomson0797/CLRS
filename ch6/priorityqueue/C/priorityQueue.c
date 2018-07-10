#include<limits.h>
#include "heap.c"

int heapMaximum(struct heap *h) {
        return h->A[0];
}

int heapExtractMaximum(struct heap *h) {
        //if(h->heapSize < 1) {
                //return INT_MIN;
        //}
        
        int max = h->A[0];
        h->A[0] = h->A[h->heapSize-1];
        h->heapSize = h->heapSize - 1;
        maxHeapify(h, 0);
        return max;
}

void heapIncreaseKey(struct heap *h, int i, int key) {
        if(key < h->A[i]) {
                return;
        }
        
        h->A[i] = key;
        while(i > 0 && h->A[parent(i)] < h->A[i]) {
                swap(h, i, parent(i));
                i = parent(i);
        }
}

void maxHeapInsert(struct heap *h, int key) {
        h->heapSize = h->heapSize + 1;
        h->A[h->heapSize-1] = INT_MIN;
        heapIncreaseKey(h, h->heapSize-1, key);
}

int main() {
        struct heap h;
        h.heapSize = 0;
        h.length = 0;

        maxHeapInsert(&h, 1);
        maxHeapInsert(&h, 2);
        maxHeapInsert(&h, 5);
        maxHeapInsert(&h, 4);

        printArray(&h);
        printf("%d\n", heapExtractMaximum(&h));
        printf("%d\n", heapExtractMaximum(&h));
}
