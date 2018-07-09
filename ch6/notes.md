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

