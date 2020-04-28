#include "sort.h"

void Swap(int* array, int l, int r) {
	int tmp = array[l];
	array[l] = array[r];
	array[r] = tmp;
}

void bubbleSort(int* array, int n) {
	//往后冒泡
	while (n) {
		int end = n;
		int flag = 1; // flag = 1 表示未交换
		for (int i = 0; i < n - 1; i++) {
			if (array[i] > array[i + 1]) {
				Swap(array, i, i + 1);
				flag = 0;
			}
		}
		if (flag)
			break;
		n--;
	}
}
//利用多次向下调整建堆
void shiftDown(int* array, int n, int parent) {
	int child = parent * 2 + 1;
	while (child < n) {
		if (child+1<n && array[child] < array[child + 1])
			child++;
		if (array[parent] < array[child])
			Swap(array, parent, child);
	}
}
//堆排序
void heapSort(int* array, int n) {
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(array, n, i);
	}
	while (n) {
		Swap(array, 0, n - 1);
		n--;
		shiftDown(array, n, 0);
	}
}
//hoar法获取基准点
int partion(int* array, int begin, int end) {

	int key = array[begin];
	int start = begin;
	while (begin < end) {
		while (begin < end && array[end] >= key) {
			end--;
		}
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		Swap(array, begin, end);
	}
	//begin 与 end 相遇
	Swap(array, start, begin);
	return begin;
}
//挖坑法
int partion1(int* array, int begin, int end) {
	int key = array[begin];
	int start = begin;
	while (begin < end) {
		//从后往前找一个比基准值小的数把填上一个坑
		while (begin < end && array[end] >= key) {
			end--;
		}
		//填坑
		array[begin] = array[end];
		//从前往后找一个比基准值大的数填上一个坑
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		//填坑
		array[end] = array[begin];
	}
	//将基准值填入坑
	array[begin] = key;
	return begin;
}
//前后指针法
int partion2(int* array, int begin, int end) {
	int prev = begin;
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end) {
		/*if (array[cur] < key && ++prev != cur) {
			Swap(array,prev,cur);
		}*/
		//cur++;
		if (array[cur] < key && prev + 1 == cur) {
			cur++;
			prev++;
		}
		else if(array[cur] > key) {
			cur++;
		}
		else {
			Swap(array, prev, cur);
		}
	}
	Swap(array, begin, prev);
	return prev;
}
//递归实现快排
void quickSort(int* array, int begin, int end) {
	if (begin >= end)
		return;
	//int keyPos = partion(array, begin, end);
	//int keyPos = partion1(array, begin, end);
	int keyPos = partion2(array, begin, end);
	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}