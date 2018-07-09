public class Heapsort {

        public void sort(int[] A) {
                int n = A.length;
                buildMaxHeap(A);
                for(int i = n - 1; i >= 0; i--) {
                        swap(A, 0, i);
                        maxHeapify(A, 0, i);
                }
        }

        public void buildMaxHeap(int[] A) {
                for(int i = A.length/2-1; i >= 0; i--) {
                        maxHeapify(A, i, A.length);
                }
        }

        public void maxHeapify(int[] A, int i, int n) {
                int largest = i;
                int l = left(i);
                int r = right(i);

                if(l < n && A[l] > A[largest]) largest = l;
                
                if(r < n && A[r] > A[largest]) largest = r;

                if(largest != i) {
                        swap(A, i, largest);
                        maxHeapify(A, largest, n);
                }
        }

        private void swap(int[] A, int i, int j) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
        }

        private int parent(int i) {
                return i/2;
        }

        private int left(int i) {
                return 2*i+1;
        }

        private int right(int i) {
                return 2*i+2;
        }

        static void printArray(int[] A) {
                for(int i = 0; i < A.length; i++) {
                        System.out.print(A[i] + ", ");
                }
                System.out.println();
        }

        public static void main(String[] args) {
                Heapsort heapsort = new Heapsort();
                int[] A = {16,14,10,8,7,9,3,2,4,1};
                heapsort.sort(A);
                printArray(A);
        }

}
