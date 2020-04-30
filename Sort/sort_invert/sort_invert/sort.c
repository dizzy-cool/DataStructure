#include "sort.h"

void invertSort(int* array, int n) {
	//当n-1是最后一个排序的末尾时,不需要再进行排序
	for (int i = 0; i < n - 1; i++) {
		//新数据插入 
		//end是有序数列的最后一个位置
		int end = i;
		//key是待插入的数据
		int key = array[end + 1];
		//找到第一个比key小的元素位置,end, end加一就是key存入的位置
		while (end >= 0 && array[end] > key) {
			//当前数据后移
			array[end + 1] = array[end];
			end--;
		}
		//将待插入的数据插入
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
		//一轮插入排序
		for (int i = 0; i < size - gap; i++) {
			//利用gap 完成逻辑分类
			//组内完成出入排序
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key) {
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;	//此处一定是end+gap,切记!! end是当前第一个小于key的下标.
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