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
// 创建返回链表的头结点.
ListNode* ListCreate(LTDataType x) {
	ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
	newHead->_data = x;
	newHead->_next = NULL;
	newHead->_prev = NULL;
	return newHead;
}
// 双向链表初始化
void ListInit(List* lst) {
	//创建头结点的空表
	lst->_header = ListCreate(0);
	lst->_header->_next = lst->_header;
	lst->_header->_prev = lst->_header;
}
// 双向链表销毁
//void ListDestory(List* lst);
// 双向链表打印
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
// 双向链表尾插
void ListPushBack(List* lst, LTDataType x) {

	ListNode* tail = lst->_header->_prev;
	ListNode* newE = ListCreate(x);
	tail->_next = newE;
	newE->_prev = tail;

	newE->_next = lst->_header;
	lst->_header->_prev = newE;
}
// 双向链表尾删
void ListPopBack(List* lst) {
	ListNode* tail = lst->_header->_prev;

	ListNode* prev = tail->_prev;
	prev->_next = tail->_next;
	lst->_header->_prev = prev;
	free(tail);
}
// 双向链表头插
void ListPushFront(List* lst, LTDataType x) {
	//ListNode* newE = ListCreate(x);
	//ListNode* first = lst->_header->_next;

	//first->_prev = newE;
	//newE->_next = first;
	////更新第一个节点
	//lst->_header->_next = newE;
	//newE->_prev = lst->_header;
	ListInsert(lst->_header->_next, x);
}
// 双向链表头删
void ListPopFront(List* lst) {
	//ListNode* first = lst->_header->_next;
	//ListNode* next = first->_next;

	//next->_prev = lst->_header;
	//free(first);
	////first = next;   //错误,不能使用局部变量修改!
	//lst->_header->_next = next;
	ListErase(lst->_header->_next);
}
// 双向链表查找
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
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