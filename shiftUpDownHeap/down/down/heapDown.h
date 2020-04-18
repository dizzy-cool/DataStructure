#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int(*cmp) (int, int);

int Little(int x, int y);

int Big(int x, int y);

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;

void Swap(HPDataType* array, int left, int right);

void heapCreat(Heap* hp, HPDataType* array, int size);

void shiftDown(HPDataType* array, int size, int parent, cmp Cmp);

void shiftUp(HPDataType* array, int child, cmp Cmp);

void heapPush(Heap* hp, HPDataType data);

void heapPop(Heap* hp);

HPDataType heapTop(Heap* hp);

void heapDestory(Heap* hp);

void heapSize(Heap* hp);

void heapEmpty(Heap* hp);

void heapPrint(Heap* hp);
