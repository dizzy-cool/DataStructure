#include "slist.h"

//typedef int SLTDateType;
//typedef struct SListNode
//{
//	SLTDateType data;
//	struct SListNode* next;
//}SListNode;


// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x) {
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}
//void SListInit(SListNode* plist) {
//	plist->data
//}
// 单链表打印
void SListPrint(SListNode* plist) {
	//用cur存储当前结点内下个结点的地址

	SListNode* cur = plist;
	
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x) {
	//1,申请内存存储新数据
	SListNode* newNode = BuySListNode(x);
	//错误示范!!! 切记要判断两次!
	//SListNode* cur = *pplist;
	//while (cur != NULL) {
	//	cur = cur->next;
	//}
	//cur->next = newNode;


	//判断两次是否为NULL
	//第一次是*pplist
	//第二次是(*pplist)->next
	if (*pplist == NULL) {
		*pplist = newNode;
	}
	else {
		//直到最后一个元素
		SListNode* last = *pplist;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newNode;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x) {
	
	SListNode* cur = *pplist;
	SListNode* newNode = BuySListNode(x);
	//判断是否为空链表
	if (cur == NULL) {
		cur = newNode;
	}
	else {
		newNode->next = cur;
		*pplist = newNode;
		//cur = newNode;  //这行代码是错误的,改变的只是形参cur的值
		//错误示范 , 这也是头插为什么一定要使用二级指针的原因!!
	}
	
}
// 单链表的尾删
void SListPopBack(SListNode** pplist) {
	SListNode* tail = *pplist;
	//检查是否为空链表
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
// 单链表头删
void SListPopFront(SListNode** pplist) {
	SListNode* cur = *pplist;
	if (cur == NULL) {
		return;
	}
	else {
		*pplist = cur->next;
		free(cur);  //此处要free,避免内存泄漏
	}
}
//// 单链表查找
//SListNode* SListFind(SListNode* plist, SLTDateType x){
//	//判断是否为空链表
//	if (plist == NULL) {
//		return NULL;
//	}
//	else {
//		while (plist->next  && plist ) {  //条件有误!!!!
//			if (plist->data == x) {
//				return plist;
//			}
//			plist = plist->next;
//		}
//		return NULL;
//	}
//}
//// 单链表在pos位置之后插入x
//// 分析思考为什么不在pos位置之前插入？
//void SListInsertAfter(SListNode* pos, SLTDateType x){
//	SListNode* Newnode = BuySListNode(x);
//	if (Newnode == NULL) {
//		pos->next = Newnode;
//		Newnode->next = pos->next;
//	}
//
//}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
//已测试  OK!
void SListEraseAfter(SListNode* pos) {
	//当前pos位置不能为空
	if (pos == NULL) {
		return ;
	}
	SListNode* cur = pos->next;
	if (cur != NULL) {
		/*连续next要保证不为空,否则cur->next会解引用空指针,是非常危险的未定义行为*/
		pos->next = cur->next;
		free(cur);
	}
	
}
// 单链表的销毁
//void SListDestory(SListNode* plist) {
//	free(plist);
//}