#include<stdio.h>
#define MAX_SIZE 1000

int main()
{
	/* Obtain input from stdin */
	int arr[MAX_SIZE];
	int N;

	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}


	/* Sort elements */
	int i;
	int key;
	for(int j = 1; j < N; j++) {
		key = arr[j];
		i = j - 1;
		while(i >= 0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i = i - 1;
		}
		arr[i+1] = key;
	}

	/* print results */
	for(i = 0; i < N; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");

	return 0;

}
