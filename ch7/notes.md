# Chapter 7: Quicksort

## 7.1 Description of Quicksort
* Quicksort, like merge sort, applies the divide-and-conquer paradigm:
    * **Divide:** partition the array A[p..r] into two subarrays A[p..q-1] and A[q+1..r] such that each element of A[p..q-1] is less than or equal to A[q], which is less than or equal to each element in A[q+1..r]
    * **Conquer:** sort the two subarrays byb recursive calls to quicksort
    * **Combine:** Because the subarrays are already sorted, no work is needed to combine
* The following procedure implements quicksort:

``` c
void quicksort(int *A, int p, int r) {
    if (p < r) {
        q = partition(A, p, r)
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}
```
* The key to the algorithm is the partition procedure, which rearranges the subarray A[p..r] in place

``` c
int partition(int *A, int p, int r) {
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r-1; j++) {
        if(A[j] <= x) {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i+1, r);
    return i+1;
}
```

* Partition always selects an element x = A[r] as a **pivot** element around which to partition the subarray A[p..r]
