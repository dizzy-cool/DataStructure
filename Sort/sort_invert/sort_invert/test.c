#include "sort.h"

void test() {
	int array[] = { 1, 5, 6, 8, 2, 3, 5,74, 52,52,52,54, 52 };
	int size = sizeof(array) / sizeof(array[0]);
	/*invertSort(array, size);
	printf("invertSort\n");
	printArray(array, size);*/

	//shellSort(array, size);
	
	/*printf("shellSort\n");
	printArray(array, size);*/


	//selectSort2(array, size);
	//printf("selectSort2\n");
	//printArray(array, size);


	//horaøÏ≈≈
	quickSort(array, 0, size - 1);
	printf("quickSort\n");
	printArray(array, size);
}


int main() {

	test();
	return 0;
}