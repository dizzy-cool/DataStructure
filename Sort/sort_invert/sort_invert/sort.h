#pragma once
#include <stdio.h>

void invertSort(int* array, int n);
void printArray(int* array, int n);

void shellSort(int* array, int size);

void selectSort(int* array, int size);
void selectSort2(int* array, int size);

int partion(int* array, int begin, int end);
int partion2(int* array, int begin, int end);
int partion3(int* array, int begin, int end);

void quickSort(int* array, int begin, int end);

void Swap(int* array, int left, int right);