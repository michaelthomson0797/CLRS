public class PriorityQueue {

        private int[] A;
        private int heapSize;
        private static final int MAXSIZE = 100;

        public PriorityQueue() {
            A = new int[MAXSIZE];
            heapSize = 0;
        }

        public int heapMaximum() {
               return A[0];
        }

        public int heapExtractMax() {
                if(heapSize < 1) {
                        System.out.println("heap underflow");
                }

                int max = A[0];
                A[0] = A[heapSize-1];
                heapSize--;
                maxHeapify(0);
                return max;
        }

        public void heapIncreaseKey(int i, int key) {
                if(key < A[i]) {
                        System.out.println("new key is smaller than current key");
                }

                A[i] = key;
                while(i > 0 && A[parent(i)] < A[i]) {
                        swap(A, i, parent(i));
                        i = parent(i);
                }
        }

        public void maxHeapInsert(int key) {
                heapSize++;
                A[heapSize-1] = Integer.MIN_VALUE;
                heapIncreaseKey(heapSize-1, key);
        }
                      

        private void buildMaxHeap() {
                for(int i = A.length/2-1; i >= 0; i--) {
                        maxHeapify(i);
                }
        }

        private void maxHeapify(int i) {
                int largest = i;
                int l = left(i);
                int r = right(i);

                if(l < heapSize && A[l] > A[largest]) largest = l;
                
                if(r < heapSize && A[r] > A[largest]) largest = r;

                if(largest != i) {
                        swap(A, i, largest);
                        maxHeapify(largest);
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

        public String toString() {
                String out = "";
                for(int i = 0; i < heapSize; i++) {
                        out += A[i] + ", ";
                }
                out += "\n";
                return out;
        }

        public static void main(String[] args) {
                PriorityQueue pq = new PriorityQueue();

                pq.maxHeapInsert(1);
                pq.maxHeapInsert(5);
                pq.maxHeapInsert(4);
                pq.maxHeapInsert(6);

                System.out.print(pq.toString());

                System.out.println("Extracted: " + pq.heapExtractMax());
                System.out.println("Extracted: " + pq.heapExtractMax());
                System.out.println("Extracted: " + pq.heapExtractMax());
                System.out.println("Extracted: " + pq.heapExtractMax());
        }

}
