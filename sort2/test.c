#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int array[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int n = sizeof(array) / sizeof(array[0]);
	//heapSort(array, n);
	//bubbleSort(array, n);
	quickSort(array, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);

	}
	system("pause");
	return 0;
}