#include <stdio.h>
#include <stdlib.h>
#include "heapDown.h"

void test(void) {
	Heap hp;
	HPDataType array[] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	int Size = sizeof(array) / sizeof(array[0]);

	heapCreat(&hp, array, Size);
	heapPrint(&hp);

	//HPDataType insertNum = 80;
	//Size++;
	//heapUpCreat(&hp, array, Size, insertNum);
	//heapPrint(&hp);
}
int main(void) {
	
	test();
	system("pause");
	return 0;
}