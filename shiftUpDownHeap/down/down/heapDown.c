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
	//��������
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

void heapCreat(Heap* hp, HPDataType* array, int size) {
	//���Ѻ���
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = size;
	
	//�����һ����Ҷ�ӽڵ㿪ʼ����  (size - 2) / 2
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftDown(hp->_array, size, parent, Big);
	}
}


//С�ѵ�һ�ֵ����µ���
void shiftDown(HPDataType* array, int size, int parent, cmp Cmp) {  //�Ӵ˸��ڵ㿪ʼ���µ���
	int child = 2 * parent + 1; //���ӵ�λ��
	while (child < size) {
		if ( child + 1 < size && Cmp(array[child] , array[child + 1])) {
			child++;
		}
		if (Cmp(array[parent], array[child])) {      //����һ�º���ָ��!!ʵ�� ��� �� С��
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
//��ѵ����ϵ���
void shiftUp(HPDataType* array, int child) {
	while (child > 0) {
		int parent = (child - 1) / 2;
		if (array[parent] < array[child]) {   //���º���ָ��
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
	//���Ѻ���
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * (size - 1));
	hp->_array[size - 1] = insertN;

	hp->_size = size;
	hp->_capacity = size;

	////�����һ����Ҷ�ӽڵ㿪ʼ����  (size - 2) / 2
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