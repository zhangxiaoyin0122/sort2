#pragma once

void Swap(int* array, int l, int r);
void bubbleSort(int* array,int n);
void shiftDown(int* array, int n, int parent);
void heapSort(int* array, int n);
//获取基准点
int partion(int* array, int begin, int end);//hoar法
int partion1(int* array, int begin, int end);//挖坑法
int partion2(int* array, int begin, int end);//双指针法

//递归实现快排
void quickSort(int* array, int begin, int end);