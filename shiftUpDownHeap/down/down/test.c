#include <stdio.h>
#include <stdlib.h>
#include "heapDown.h"
#include "sort.h"

void test(void) {
	Heap hp;
	HPDataType array[] = { 93,80,48,53,72,30,18,36,15,35,45 };
	int Size = sizeof(array) / sizeof(array[0]);

	heapCreat(&hp, array, Size);
	heapPrint(&hp);

	//heapPush(&hp, 150);
	//heapPrint(&hp);

	heapPop(&hp);
	heapPrint(&hp);

}

void test2(void) {
	HPDataType array[] = { 93,80,48,53,72,30,18,36,15,35,45 };
	heapSort(array, sizeof(array) / sizeof(array[0]));
	int i = 0;
	while (i < sizeof(array) / sizeof(array[0])) {
		printf("%d ", array[i]);
		printf("\n");
		i++;
	}
}
int main(void) {
	
	TestTopk();
	system("pause");
	return 0;
}