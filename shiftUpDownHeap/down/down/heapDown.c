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
//����
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
//�ѵ����ϵ���
void shiftUp(HPDataType* array, int child, cmp Cmp) {
	while (child > 0) {
		int parent = (child - 1) / 2;
		if (Cmp(array[parent] , array[child])) {   //��� parent < childʱ,����
			Swap(array, parent, child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
// �ѵĲ���
void heapPush(Heap* hp, HPDataType data) {

	//1.β��,�������
	if (hp->_size >= hp->_capacity) {
		hp->_capacity = hp->_size * 2;
		hp->_array = (HPDataType*) realloc(hp->_array, hp->_capacity * sizeof(HPDataType));  //realloc\malloc\calloc����������ڴ浥λ���ֽ�,Ҫע��sizeof
	}
	hp->_array[hp->_size++] = data;
	//2.���ϵ���
	shiftUp(hp->_array, hp->_size-1, Big);			//childλ�õ�ȷ��	
}

void heapPop(Heap* hp) {
	Swap(hp->_array, 0, hp->_size - 1);
	hp->_size--;		//αɾ��
	shiftDown(hp->_array, hp->_size, 0, Big);
}
//ȡ�Ѷ�Ԫ��
HPDataType heapTop(Heap* hp) {
	return hp->_array[0];
}
//�ѵ�����
void heapDestory(Heap* hp) {
	free(hp->_array);
}
//�ѵ����ݸ���
void heapSize(Heap* hp) {
	return hp->_size;
}
//�ѵ��п�
void heapEmpty(Heap* hp) {
	if (hp->_size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
//�ѵĴ�ӡ
void heapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}