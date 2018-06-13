import java.util.Scanner;

public class insertionSort {
	public static void main(String[] args) {

		/* Obtain numbers from standard input */
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int[] A = new int[N];

		for(int i = 0; i < N; i++) {
			A[i] = in.nextInt();
		}
		
		/* Sort the elements using insertion sort */
		int key;
		int i;
		for(int j = 1; j < N; j++) {
			key = A[j];
			i = j-1;
			while(i >= 0 && A[i] > key) {
				A[i+1] = A[i];
				i = i - 1;
			}
			A[i+1] = key;
		}

		/* Print the output */
		for(i = 0; i < N; i++) {
			System.out.printf("%d, ", A[i]);
		}
		System.out.println();
	}
}
