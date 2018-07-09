# Chapter 6 Heapsort

## 6.1 Heaps
* The (binary) heap data structure is an array object we can view as a complete binary tree
* An array A that represents a heap is an object that has two attributes: A.length and A.heap-size, which represents how many elements in the heap are stored in A
* The root of the tree is A[1]
* Given the index of a node, we can easily find the parent, left child, and right child:

```C
int parent(int i) {
    return i/2;
}

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}
```

* There are two kinds of binary heaps: **max-heaps** and **min-heaps**
    * in a **max-heap**, the **max-heap property** is that for very node i, other tthan the root, A[parent(i)] >= A[i]
    * A **min-heap** is organized in the opposite way; the **min-heap property** is that for every node i other than the root, A[parent(i)] <= A[i]
* Viewing a heap as a tree, we define the **height** of a node in a heap to be the number of edges on the longest simple downward path from the node to a leaf
* We define the height of a tree as the height of it's root
* Since it is a binary tree, its height is Omega(lg n)
The remainder of the chapter will focus on basic procedures on heaps

## 6.2 Maintaining the Heap Property
* In order to maintain the max-heap property, we call the precedure max-heapify
* its inputs are an array A and an index i into the array
* max-heapify letes the value at A[i] "float down" in the max-heap sot hat the subtree rooted at i obeys the max-heap property

```C
void maxHeapify(int* A, int i) {
    int largest
    int l = left(i);
    int r = right(i);

    if(l <= A.heapSize && A[l] > A[i]) {
        largest = l;
    else largest = i;

    if(r <= A.heapSize && A[r] > A[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(A, i, largest);
        maxHeapify(A, largest)
    }
}
```
* The largest of A[left(i)], A[i], and A[right(i)] is determined and stored in _largest_.
    * If A[i] is the largest, the max-heap property is already held
    * Otherwise, one of the two children has the largest element and is swapped with A[i]
    * Then the prcess is started again at with A[largest] which now has the value of A[i]


## 6.3 Building a Heap
* We can use the procedure maxHeapify in a bottom-up manner to convert an array into a max-heap
* The procedure buildMaxHeap goes through all nodes which arent leaves and runs maxHeapify on them

```C
void buildMaxHeap(int* A) {
    A.heapSize = A.length
    for(int i = A.length/2; i >= 1; i--) {
        maxHeapify(A,i);
    }
}
```

## 6.4 The Heapsort Algorithm
* The heapsort algorithm starts by using buildMaxHeap to build a max-heap on the input array A
* Since the maximum element of the array is stored at A[1], we can put it into its correct final position by exchanging it with A[n]
* We can now dispose of node n from the heap by simply decrementing A.heapSize
* Then call maxHeapify on the new root

```C
void heapsort(int* A) {
    buildMaxHeap(A);
    for(int i = A.length; i >= 2; i--) {
        swap(A, 1, i);
        A.heapSize = A.heapSize - 1;
        maxHeapify(A, 1);
    }
}
```
