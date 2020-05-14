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
			if (array[i] > array[i + gap]) {
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

void selectSort(int* array, int size) {
	int bound = 0;
	//[0 bound] 已排序区间
	//[bound+1 size - 1] 未排序区间
	int min = array[0];

	for (; bound < size; bound++) {
		//区间最小值的下标
		int idx = bound + 1;
		min = array[idx];
		//找到未排序区间的最小值
		for (int i = bound + 1; i < size - 1; i++) {				
			if (min > array[i + 1]) {
				min = array[i + 1];
				idx = i + 1;
			}
		}
		Swap(array, bound + 1, idx);
	}
}

void selectSort2(int* array, int size) {
	int begin = 0;
	int end = size - 1;

	while (begin < end) {
		//每次选择最大值和最小值, 最后把最大值放在右侧,最小值放在左侧
		int min = begin;
		int max = begin;

		for (int i = begin + 1; i <= end; i++) {
			
			//更新最大 最小的下标
			if (array[i] < array[min]) {
				min = i;
			}
			if (array[i] >= array[max]) {
				max = i;
			}
		}
		//交换位置,最小值放在begin位置上
		Swap(array, begin, min);
		//如果最大值的位置是begin,要更新max位置
		if (max == begin) {
			max = min;
		}
		//最大值放在end位置
		Swap(array, end, max);
		begin++;
		end--;
	}
}
//快速排序的第一种划分方法: hora划分区间
int partion(int* array, int begin, int end) {
	//以升序为例
	//基准值val 为未排序区间的首元素
	int val = array[begin];
	int start = begin;
	while (begin < end) {
		//从待划分区间的末尾开始向前找第一个小于val的值
		while (begin < end && array[end] >= val) {
			end--;
		}
		//从带划分区间的开头向后找第一个大于val的值
		while (begin < end && array[begin] <= val) {
			begin++;
		}
		//交换
		Swap(array, begin, end);
	}
	//val和相遇位置交换
	if (begin == end) {
		Swap(array, start,	begin);
	}
	//返回基准值位置
	return begin;
}

//第二种划分方法: 挖坑法
int partion2(int* array, int begin, int end) {
	//找基准值
	int val = array[begin];

	while (begin < end) {
		//待划分区间从后往前找第一个小于基准值的位置
		while (begin < end && array[end] >= val) {
			end--;
		}
		//填坑
		array[begin] = array[end];
		//待划分区间从前往后找第一个大于基准值的位置
		while (begin < end && array[begin] <= val) {
			begin++;
		}
		//填坑
		array[end] = array[begin];
	}
	//相遇点填入基准值
	if (begin == end) {
		array[begin] = val;
	}
	return begin;
}
//第三种划分方法: 前后指针法
int partion3(int* array, int begin, int end) {
	//prev: cur之前的最后一个小于基准值的位置
	int prev = begin;
	//cur: 新发现的下一个小于基准值的位置
	int cur = prev + 1;
	//基准值
	int val = array[begin];

	//完成一轮的调整
	while (cur <= end) {
		//前后指针是否连续,连续说明中间没有大于基准值的数据
		//大于基准值的向后移动, 小于基准值的向前移动
		if (array[cur] < val && prev + 1 != cur) {
			prev++;
			Swap(array, prev, cur);
		}
		cur++;
	}
	//交换基准值和最后一个小于基准值的位置
	Swap(array, begin, prev);
	//返回最新基准值的位置
	return prev;
}

//快速排序(递归实现)
void quickSort(int* array, int begin, int end) {
	if (begin >= end) {
		return;
	}
	//划分当前区间
	int valPos = partion3(array, begin, end);
	//划分子区间
	quickSort(array, begin, valPos - 1);
	quickSort(array, valPos + 1, end);
}

//数组元素交换
void Swap(int* array, int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

//打印数组
void printArray(int* array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}