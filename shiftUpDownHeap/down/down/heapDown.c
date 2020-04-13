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
//大堆的向上调整
void shiftUp(HPDataType* array, int child) {
	while (child > 0) {
		int parent = (child - 1) / 2;
		if (array[parent] < array[child]) {   //试下函数指针
			Swap(array, parent, child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
void heapUpCreat(Heap* hp, HPDataType* array, int size, int insertN) {
	//建堆函数
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * (size - 1));
	hp->_array[size - 1] = insertN;

	hp->_size = size;
	hp->_capacity = size;

	////从最后一个非叶子节点开始建堆  (size - 2) / 2
	//for (int parent = (size - 2) / 2; parent >= 0; parent--) {
	//	shiftUp(hp->_array, parent);
	//}
	//shiftUp(array, size);

}
void heapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}