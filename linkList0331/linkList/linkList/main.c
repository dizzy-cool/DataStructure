#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void test(void) {
	SListNode* sl = BuySListNode(1);
	//SListPrint(sl);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushFront(&sl, 0);
//	SListPopFront(&sl);
	
	//SListPushBack(&sl, 3);
	//SListPushBack(&sl, 4);
	//SListPopBack(&sl);
	SListPrint(sl);
	//SListNode* find = SListFind(&sl, 2);
	//SListPrint(find);

	SListEraseAfter(sl);
	SListPrint(sl);
}
int main(void) {
	
	test();
	
	system("pause");
	return 0;
}