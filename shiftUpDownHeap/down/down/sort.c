#include "sort.h"
// ��������ж�����
void heapSort(HPDataType* array, int size) {
	//����
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftDown(array, size, parent, Big);
	}
	while (size > 0) {
		Swap(array, 0, size - 1);
		size--;
		shiftDown(array, size, 0, Big);
	}
	printf("\n");
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(HPDataType* array, int n, int k, cmp Cmp) {
	int size = k;
	for (int parent = (k - 2) / 2; parent >= 0; parent--) {
		shiftDown(array, size, parent, Cmp);
		//�����,���մ�С��������
	}
	int i = k ;
	for (; i < n; i++) {
		//1.�öѶ�Ԫ�ظ�ʣ�µ�Ԫ�رȽ�,
		//	���Ѷ�Ԫ��С,��ѶѶ�����,�����µ���
		if (Cmp(array[i], array[0])) {
			Swap(array, 0, i);
			//���������µ���
			shiftDown(array, size, 0, Cmp);
		}	
	}
	i = 0;
	while (i < size) {
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
} 
void TestTopk() {
	HPDataType array[] = { 13, 23, 19, 144, 1, 3, 2, 4, 5, 23, 56, 26, 36, 46, 86, 96, 76 };
	PrintTopK(array, sizeof(array) / sizeof(array[0]), 10, Big);
	//Big	ָ���ǽ����,����С��top10
	//Littleָ���ǽ�С��,������top10
}

