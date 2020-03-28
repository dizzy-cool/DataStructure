#include <stdio.h>
#include "seqList.h"

#define ADD_CAPACITY 20

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps) {
	ps->capacity = 10; //初始值为10
	ps->size = 0;
	ps->a = (SLDateType*)malloc(ps->capacity * sizeof(SLDateType));
	
}
void SeqListDestory(SeqList* ps) {
	free(ps->a);
}

void SeqListPrint(SeqList* ps) {
	size_t i = 0;
	printf("执行打印\n");
	for (; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//扩容 ADD_CAPACITY
void reallocPs(SeqList* ps) {
	ps->a = realloc(ps->a, ADD_CAPACITY * sizeof(SeqList));
}
//尾插
void SeqListPushBack(SeqList* ps, SLDateType x) {
	
	//触发扩容
	if (ps->size >= ps->capacity) {
		reallocPs(ps);
	}
	ps->a[ps->size] = x;
	ps->size++;

}
void SeqListPushFront(SeqList* ps, SLDateType x) {
	if (ps->size >= ps->capacity) {
		reallocPs(ps);
	}
	size_t i = ps->size;
	for (; i > 0; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;

	ps->size++;
}
//前删
void SeqListPopFront(SeqList* ps) {
	size_t i = 0;
	for (; i < ps->size - 1; i++) {
		// 0 - size-1 删除之前,是size个
		// 0 - size-2 删除之后,是size-1个
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps) {
	ps->size--;
}
// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x) {
	size_t i = 0;
	for (; i < ps->size; i++) {
		if (ps->a[i] == x){
			printf("已找到表中的 %d 的下标: %u\n", x, i);
			return (int)i;
			//返回下标
		}
	}
	printf("表中没有您要找的元素;\n");
	return -1;

}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x) {
	size_t i = ps->size;
	for (; i >= pos; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos) {
	for (; pos < ps->size - 1; pos++) {
		ps->a[pos] = ps->a[pos + 1];
	}
	ps->size--;
}
