#include "heapDown.h"
#include <string.h>


//typedef int(*cmp) (int, int);

int Little(int x, int y) {
	return x > y ? 1 : 0;
}
int Big(int x, int y) {
	return x < y ? 1 : 0;
}

void Swap(HPDataType* array, int left, int right) {
	//交换函数
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}
//建堆
void heapCreat(Heap* hp, HPDataType* array, int size) {
	//建堆函数
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = size;
	
	//从最后一个非叶子节点开始建堆  (size - 2) / 2
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftDown(hp->_array, size, parent, Big);
	}
}


//小堆的一轮的向下调整
void shiftDown(HPDataType* array, int size, int parent, cmp Cmp) {  //从此父节点开始向下调整
	int child = 2 * parent + 1; //左孩子的位置
	while (child < size) {
		if ( child + 1 < size && Cmp(array[child] , array[child + 1])) {
			child++;
		}
		if (Cmp(array[parent], array[child])) {      //考虑一下函数指针!!实现 大堆 和 小堆
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
//堆的向上调整
void shiftUp(HPDataType* array, int child, cmp Cmp) {
	while (child > 0) {
		int parent = (child - 1) / 2;
		if (Cmp(array[parent] , array[child])) {   //大堆 parent < child时,交换
			Swap(array, parent, child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
// 堆的插入
void heapPush(Heap* hp, HPDataType data) {

	//1.尾插,检查容量
	if (hp->_size >= hp->_capacity) {
		hp->_capacity = hp->_size * 2;
		hp->_array = (HPDataType*) realloc(hp->_array, hp->_capacity * sizeof(HPDataType));  //realloc\malloc\calloc函数申请的内存单位是字节,要注意sizeof
	}
	hp->_array[hp->_size++] = data;
	//2.向上调整
	shiftUp(hp->_array, hp->_size-1, Big);			//child位置的确认	
}

void heapPop(Heap* hp) {
	Swap(hp->_array, 0, hp->_size - 1);
	hp->_size--;		//伪删除
	shiftDown(hp->_array, hp->_size, 0, Big);
}
//取堆顶元素
HPDataType heapTop(Heap* hp) {
	return hp->_array[0];
}
//堆的销毁
void heapDestory(Heap* hp) {
	free(hp->_array);
}
//堆的数据个数
void heapSize(Heap* hp) {
	return hp->_size;
}
//堆的判空
void heapEmpty(Heap* hp) {
	if (hp->_size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
//堆的打印
void heapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}