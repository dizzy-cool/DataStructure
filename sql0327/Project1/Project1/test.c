#include <stdio.h>
#include <stdlib.h>
#include "seqList.h"


void test(SeqList* ps) {
	SeqListInit(ps);
	//SeqListPushBack(ps, 1);
	//SeqListPushBack(ps, 2);
	//SeqListPushBack(ps, 3);

	SeqListPushFront(ps, 3);
	SeqListPushFront(ps, 2);
	SeqListPushFront(ps, 1);




	SeqListPrint(ps);
	//SeqListPopFront(ps);
	//SeqListPopBack(ps);
	//SeqListInsert(ps, 1, 5);
	SeqListErase(ps, 1);
	SeqListPrint(ps);
	//int i = SeqListFind(ps, 1);

	
	SeqListDestory(ps);

}

int main(void) {
	
	SeqList* ps = (SeqList*)malloc(sizeof(SeqList));

	test(ps);

	free(ps);
	system("pause");
	return 0;
}