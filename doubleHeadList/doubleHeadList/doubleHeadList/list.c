#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//typedef struct ListNode
//{
//	LTDataType _data;
//	struct ListNode* _next;
//	struct ListNode* _prev;
//}ListNode;
//typedef ListNode* struct List {
//	struct ListNode*  _header;
//}List;
// �������������ͷ���.
ListNode* ListCreate(LTDataType x) {
	ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
	newHead->_data = x;
	newHead->_next = NULL;
	newHead->_prev = NULL;
	return newHead;
}
// ˫�������ʼ��
void ListInit(List* lst) {
	//����ͷ���Ŀձ�
	lst->_header = ListCreate(0);
	lst->_header->_next = lst->_header;
	lst->_header->_prev = lst->_header;
}
// ˫����������
//void ListDestory(List* lst);
// ˫�������ӡ
void ListPrint(List* lst) {
	ListNode* cur = lst->_header->_next;

	if (cur == NULL) {
		return;
	}
	else {
		while (cur != lst->_header) {
			ListNode* next = cur->_next;
			printf("%d ", cur->_data);
			cur = next;
		}
		printf("\n");
	}
}
// ˫������β��
void ListPushBack(List* lst, LTDataType x) {

	ListNode* tail = lst->_header->_prev;
	ListNode* newE = ListCreate(x);
	tail->_next = newE;
	newE->_prev = tail;

	newE->_next = lst->_header;
	lst->_header->_prev = newE;
}
// ˫������βɾ
void ListPopBack(List* lst) {
	ListNode* tail = lst->_header->_prev;

	ListNode* prev = tail->_prev;
	prev->_next = tail->_next;
	lst->_header->_prev = prev;
	free(tail);
}
// ˫������ͷ��
void ListPushFront(List* lst, LTDataType x) {
	//ListNode* newE = ListCreate(x);
	//ListNode* first = lst->_header->_next;

	//first->_prev = newE;
	//newE->_next = first;
	////���µ�һ���ڵ�
	//lst->_header->_next = newE;
	//newE->_prev = lst->_header;
	ListInsert(lst->_header->_next, x);
}
// ˫������ͷɾ
void ListPopFront(List* lst) {
	//ListNode* first = lst->_header->_next;
	//ListNode* next = first->_next;

	//next->_prev = lst->_header;
	//free(first);
	////first = next;   //����,����ʹ�þֲ������޸�!
	//lst->_header->_next = next;
	ListErase(lst->_header->_next);
}
// ˫���������
List* ListFind(List* lst, LTDataType x) {
	ListNode* cur = lst->_header->_next;

	while (cur != lst->_header) {
		if (cur->_data == x) {
			return cur;
		}
		else {
			cur = cur->_next;
		}
	}
	return NULL;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* node = ListCreate(x);
	ListNode* cur, *prev, *next;
	next = pos->_next;
	prev = pos->_prev;
	
	prev->_next = node;
	node->_prev = prev;

	node->_next = pos;
	next->_prev = pos;

}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {

	ListNode* prev, *next;
	prev = pos->_prev;
	next = pos->_next;
	if (next->_next == next) {
		return;
	}

	prev->_next = next;
	next->_prev = prev;
}