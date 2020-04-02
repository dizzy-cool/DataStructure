#include "slist.h"

//typedef int SLTDateType;
//typedef struct SListNode
//{
//	SLTDateType data;
//	struct SListNode* next;
//}SListNode;


// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x) {
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}
//void SListInit(SListNode* plist) {
//	plist->data
//}
// �������ӡ
void SListPrint(SListNode* plist) {
	//��cur�洢��ǰ������¸����ĵ�ַ

	SListNode* cur = plist;
	
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x) {
	//1,�����ڴ�洢������
	SListNode* newNode = BuySListNode(x);
	//����ʾ��!!! �м�Ҫ�ж�����!
	//SListNode* cur = *pplist;
	//while (cur != NULL) {
	//	cur = cur->next;
	//}
	//cur->next = newNode;


	//�ж������Ƿ�ΪNULL
	//��һ����*pplist
	//�ڶ�����(*pplist)->next
	if (*pplist == NULL) {
		*pplist = newNode;
	}
	else {
		//ֱ�����һ��Ԫ��
		SListNode* last = *pplist;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newNode;
	}
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x) {
	
	SListNode* cur = *pplist;
	SListNode* newNode = BuySListNode(x);
	//�ж��Ƿ�Ϊ������
	if (cur == NULL) {
		cur = newNode;
	}
	else {
		newNode->next = cur;
		*pplist = newNode;
		//cur = newNode;  //���д����Ǵ����,�ı��ֻ���β�cur��ֵ
		//����ʾ�� , ��Ҳ��ͷ��Ϊʲôһ��Ҫʹ�ö���ָ���ԭ��!!
	}
	
}
// �������βɾ
void SListPopBack(SListNode** pplist) {
	SListNode* tail = *pplist;
	//����Ƿ�Ϊ������
	if (tail == NULL) {
		return ;
	}
	else {
		SListNode* prev = NULL;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist) {
	SListNode* cur = *pplist;
	if (cur == NULL) {
		return;
	}
	else {
		*pplist = cur->next;
		free(cur);  //�˴�Ҫfree,�����ڴ�й©
	}
}
//// ���������
//SListNode* SListFind(SListNode* plist, SLTDateType x){
//	//�ж��Ƿ�Ϊ������
//	if (plist == NULL) {
//		return NULL;
//	}
//	else {
//		while (plist->next  && plist ) {  //��������!!!!
//			if (plist->data == x) {
//				return plist;
//			}
//			plist = plist->next;
//		}
//		return NULL;
//	}
//}
//// ��������posλ��֮�����x
//// ����˼��Ϊʲô����posλ��֮ǰ���룿
//void SListInsertAfter(SListNode* pos, SLTDateType x){
//	SListNode* Newnode = BuySListNode(x);
//	if (Newnode == NULL) {
//		pos->next = Newnode;
//		Newnode->next = pos->next;
//	}
//
//}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
//�Ѳ���  OK!
void SListEraseAfter(SListNode* pos) {
	//��ǰposλ�ò���Ϊ��
	if (pos == NULL) {
		return ;
	}
	SListNode* cur = pos->next;
	if (cur != NULL) {
		/*����nextҪ��֤��Ϊ��,����cur->next������ÿ�ָ��,�Ƿǳ�Σ�յ�δ������Ϊ*/
		pos->next = cur->next;
		free(cur);
	}
	
}
// �����������
//void SListDestory(SListNode* plist) {
//	free(plist);
//}