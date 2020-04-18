#include "sort.h"
// 对数组进行堆排序
void heapSort(HPDataType* array, int size) {
	//建堆
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

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(HPDataType* array, int n, int k, cmp Cmp) {
	int size = k;
	for (int parent = (k - 2) / 2; parent >= 0; parent--) {
		shiftDown(array, size, parent, Cmp);
		//建大堆,按照从小到大排序
	}
	int i = k ;
	for (; i < n; i++) {
		//1.用堆顶元素跟剩下的元素比较,
		//	若堆顶元素小,则把堆顶更换,再向下调整
		if (Cmp(array[i], array[0])) {
			Swap(array, 0, i);
			//更换后向下调整
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
	//Big	指的是建大堆,找最小的top10
	//Little指的是建小堆,找最大的top10
}

