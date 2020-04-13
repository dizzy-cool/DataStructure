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

// �������������ͷ���.
ListNode* ListCreate(LTDataType x);
// ˫�������ʼ��
void ListInit(List* lst);
// ˫����������
void ListDestory(List* lst);
// ˫�������ӡ
void ListPrint(List* lst);
// ˫������β��
void ListPushBack(List* lst, LTDataType x);
// ˫������βɾ
void ListPopBack(List* lst);
// ˫������ͷ��
void ListPushFront(List* lst, LTDataType x);
// ˫������ͷɾ
void ListPopFront(List* lst);
// ˫���������
List* ListFind(List* lst, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);