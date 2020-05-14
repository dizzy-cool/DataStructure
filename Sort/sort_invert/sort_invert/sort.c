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

void selectSort(int* array, int size) {
	int bound = 0;
	//[0 bound] ����������
	//[bound+1 size - 1] δ��������
	int min = array[0];

	for (; bound < size; bound++) {
		//������Сֵ���±�
		int idx = bound + 1;
		min = array[idx];
		//�ҵ�δ�����������Сֵ
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
		//ÿ��ѡ�����ֵ����Сֵ, �������ֵ�����Ҳ�,��Сֵ�������
		int min = begin;
		int max = begin;

		for (int i = begin + 1; i <= end; i++) {
			
			//������� ��С���±�
			if (array[i] < array[min]) {
				min = i;
			}
			if (array[i] >= array[max]) {
				max = i;
			}
		}
		//����λ��,��Сֵ����beginλ����
		Swap(array, begin, min);
		//������ֵ��λ����begin,Ҫ����maxλ��
		if (max == begin) {
			max = min;
		}
		//���ֵ����endλ��
		Swap(array, end, max);
		begin++;
		end--;
	}
}
//��������ĵ�һ�ֻ��ַ���: hora��������
int partion(int* array, int begin, int end) {
	//������Ϊ��
	//��׼ֵval Ϊδ�����������Ԫ��
	int val = array[begin];
	int start = begin;
	while (begin < end) {
		//�Ӵ����������ĩβ��ʼ��ǰ�ҵ�һ��С��val��ֵ
		while (begin < end && array[end] >= val) {
			end--;
		}
		//�Ӵ���������Ŀ�ͷ����ҵ�һ������val��ֵ
		while (begin < end && array[begin] <= val) {
			begin++;
		}
		//����
		Swap(array, begin, end);
	}
	//val������λ�ý���
	if (begin == end) {
		Swap(array, start,	begin);
	}
	//���ػ�׼ֵλ��
	return begin;
}

//�ڶ��ֻ��ַ���: �ڿӷ�
int partion2(int* array, int begin, int end) {
	//�һ�׼ֵ
	int val = array[begin];

	while (begin < end) {
		//����������Ӻ���ǰ�ҵ�һ��С�ڻ�׼ֵ��λ��
		while (begin < end && array[end] >= val) {
			end--;
		}
		//���
		array[begin] = array[end];
		//�����������ǰ�����ҵ�һ�����ڻ�׼ֵ��λ��
		while (begin < end && array[begin] <= val) {
			begin++;
		}
		//���
		array[end] = array[begin];
	}
	//�����������׼ֵ
	if (begin == end) {
		array[begin] = val;
	}
	return begin;
}
//�����ֻ��ַ���: ǰ��ָ�뷨
int partion3(int* array, int begin, int end) {
	//prev: cur֮ǰ�����һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//cur: �·��ֵ���һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;
	//��׼ֵ
	int val = array[begin];

	//���һ�ֵĵ���
	while (cur <= end) {
		//ǰ��ָ���Ƿ�����,����˵���м�û�д��ڻ�׼ֵ������
		//���ڻ�׼ֵ������ƶ�, С�ڻ�׼ֵ����ǰ�ƶ�
		if (array[cur] < val && prev + 1 != cur) {
			prev++;
			Swap(array, prev, cur);
		}
		cur++;
	}
	//������׼ֵ�����һ��С�ڻ�׼ֵ��λ��
	Swap(array, begin, prev);
	//�������»�׼ֵ��λ��
	return prev;
}

//��������(�ݹ�ʵ��)
void quickSort(int* array, int begin, int end) {
	if (begin >= end) {
		return;
	}
	//���ֵ�ǰ����
	int valPos = partion3(array, begin, end);
	//����������
	quickSort(array, begin, valPos - 1);
	quickSort(array, valPos + 1, end);
}

//����Ԫ�ؽ���
void Swap(int* array, int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

//��ӡ����
void printArray(int* array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}