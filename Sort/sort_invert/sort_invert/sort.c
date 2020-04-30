#include "sort.h"

void invertSort(int* array, int n) {
	//��n-1�����һ�������ĩβʱ,����Ҫ�ٽ�������
	for (int i = 0; i < n - 1; i++) {
		//�����ݲ��� 
		//end���������е����һ��λ��
		int end = i;
		//key�Ǵ����������
		int key = array[end + 1];
		//�ҵ���һ����keyС��Ԫ��λ��,end, end��һ����key�����λ��
		while (end >= 0 && array[end] > key) {
			//��ǰ���ݺ���
			array[end + 1] = array[end];
			end--;
		}
		//������������ݲ���
		array[end + 1] = key;
	}
}

void shellSort(int* array, int size) {
	int gap = size;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++) {
			if ( array[i] > array[i + gap]) {
				Swap(array, i, i + gap);
			}
		}
	}
}
void shellSort2(int* array, int size) {
	int gap = size;
	while (gap > 1) {
		gap = gap / 3 + 1;
		//һ�ֲ�������
		for (int i = 0; i < size - gap; i++) {
			//����gap ����߼�����
			//������ɳ�������
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key) {
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;	//�˴�һ����end+gap,�м�!! end�ǵ�ǰ��һ��С��key���±�.
		}
		
	}

}

void Swap(int* array, int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

void printArray(int* array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}