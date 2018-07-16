public class Quicksort {
        public void sort(int[] A, int p, int r) {
                if(p < r) {
                        int q = partition(A,p,r);
                        sort(A,p,q-1);
                        sort(A,q+1,r);
                }
        }

        private int partition(int[] A, int p, int r) {
                int x = A[r];
                int i = p - 1;

                for(int j = p; j < r; j++) {
                        if(A[j] <= x) {
                                i++;
                                swap(A, i ,j);
                        }
                }
                swap(A, i+1, r);
                return i+1;
        }

        private void swap(int[] A, int i, int j) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
        }

        public static void printArray(int[] A) {
                for(int i = 0; i < A.length; i++) {
                        System.out.printf("%d, ", A[i]);
                }
                System.out.println();
        }

        public static void main(String[] args) {
                int[] A = {2,8,7,1,3,5,6,4};

                Quicksort quicksort = new Quicksort();

                quicksort.sort(A, 0, A.length-1);
                printArray(A);
        }
}
