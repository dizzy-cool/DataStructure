#include <stdio.h>
#include "seqList.h"

#define ADD_CAPACITY 20

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps) {
	ps->capacity = 10; //��ʼֵΪ10
	ps->size = 0;
	ps->a = (SLDateType*)malloc(ps->capacity * sizeof(SLDateType));
	
}
void SeqListDestory(SeqList* ps) {
	free(ps->a);
}

void SeqListPrint(SeqList* ps) {
	size_t i = 0;
	printf("ִ�д�ӡ\n");
	for (; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//���� ADD_CAPACITY
void reallocPs(SeqList* ps) {
	ps->a = realloc(ps->a, ADD_CAPACITY * sizeof(SeqList));
}
//β��
void SeqListPushBack(SeqList* ps, SLDateType x) {
	
	//��������
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
//ǰɾ
void SeqListPopFront(SeqList* ps) {
	size_t i = 0;
	for (; i < ps->size - 1; i++) {
		// 0 - size-1 ɾ��֮ǰ,��size��
		// 0 - size-2 ɾ��֮��,��size-1��
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps) {
	ps->size--;
}
// ˳������
int SeqListFind(SeqList* ps, SLDateType x) {
	size_t i = 0;
	for (; i < ps->size; i++) {
		if (ps->a[i] == x){
			printf("���ҵ����е� %d ���±�: %u\n", x, i);
			return (int)i;
			//�����±�
		}
	}
	printf("����û����Ҫ�ҵ�Ԫ��;\n");
	return -1;

}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x) {
	size_t i = ps->size;
	for (; i >= pos; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos) {
	for (; pos < ps->size - 1; pos++) {
		ps->a[pos] = ps->a[pos + 1];
	}
	ps->size--;
}
