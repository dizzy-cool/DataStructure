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

void heapUpCreat(Heap* hp, HPDataType* array, int size, int insertN);

void shiftDown(HPDataType* array, int size, int parent);

//void shiftUp(HPDataType* array, int child);

void heapPrint(Heap* hp);
