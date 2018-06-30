import java.util.Scanner;

public class MergeSort {

	public static void merge(int[] A, int p, int q, int r) {
		int i, j;

		/* find length of two halves */
		int n1 = q - p + 1;
		int n2 = r - q;

		/* create arrays for each half */
		int[] L = new int[n1+1];
		int[] R = new int[n2+1];

		/* populate the two halves */
		for(i = 0; i < n1; i++) {
			L[i] = A[p+i];
		}
		for (j = 0; j < n2; j++) {
			R[j] = A[q+1+j];
		}

		/* place sentinel at last position */
		L[n1] = Integer.MAX_VALUE;
		R[n2] = Integer.MAX_VALUE;

		/* merge the two halves back into the original array */
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

	/* merge sort driver */
	public static void mergeSort(int[] A, int p, int r) {
		if (p < r) {
			int q = (p + r)/2;
			mergeSort(A, p, q);
			mergeSort(A, q+1, r);
			merge(A, p, q, r);
		}
	}

	/* Prints array to standard out */
	public static void printArray(int[] A) {
		for(int i = 0; i < A.length; i++) {
			System.out.printf(" %d,", A[i]);
		}
	}

	public static void main(String[] args) {
		/* Obtain numbers from standard input */
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int[] A = new int[N];

		for(int i = 0; i < N; i++) {
			A[i] = in.nextInt();
		}

		/* Run merge sort on entire array */
		mergeSort(A, 0, A.length-1);
		printArray(A);
	}
}

