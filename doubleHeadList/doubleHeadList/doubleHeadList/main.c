#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void test() {
	List lst;
	ListInit(&lst);
	ListPushBack(&lst, 1);
	ListPushBack(&lst, 2);
	ListPushBack(&lst, 3);
	ListPushBack(&lst, 4);
	ListPushFront(&lst, 9);

	ListPrint(&lst);
	
	ListPopFront(&lst);
	//ListPopBack(&lst);
	ListPrint(&lst);
	List* find = ListFind(&lst, 2);
	if (find != NULL) {
		printf("已经找到%d 0X%x \n", 2, find);
	}
	else {
		printf("没有找到2!\n");
	}




}
int main(void) {
	
	
	test();
	system("pause");
	return 0;
}