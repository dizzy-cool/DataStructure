#include "sort.h"

void test() {
	int array[] = { 1, 5, 6, 8, 2, 3, 74, 54, 52 };
	int size = sizeof(array) / sizeof(array[0]);
	/*invertSort(array, size);
	printf("invertSort\n");
	printArray(array, size);*/
	shellSort(array, size);
	printf("shellSort\n");
	printArray(array, size);
}


int main() {

	test();
	return 0;
}