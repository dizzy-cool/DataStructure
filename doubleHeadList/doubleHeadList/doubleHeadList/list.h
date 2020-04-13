#pragma  once
#include <stdio.h>
#include <stdlib.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef  struct List {
	struct ListNode*  _header;
}List;

// 创建返回链表的头结点.
ListNode* ListCreate(LTDataType x);
// 双向链表初始化
void ListInit(List* lst);
// 双向链表销毁
void ListDestory(List* lst);
// 双向链表打印
void ListPrint(List* lst);
// 双向链表尾插
void ListPushBack(List* lst, LTDataType x);
// 双向链表尾删
void ListPopBack(List* lst);
// 双向链表头插
void ListPushFront(List* lst, LTDataType x);
// 双向链表头删
void ListPopFront(List* lst);
// 双向链表查找
List* ListFind(List* lst, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);