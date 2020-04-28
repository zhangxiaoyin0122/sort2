#include "sort.h"

void Swap(int* array, int l, int r) {
	int tmp = array[l];
	array[l] = array[r];
	array[r] = tmp;
}

void bubbleSort(int* array, int n) {
	//����ð��
	while (n) {
		int end = n;
		int flag = 1; // flag = 1 ��ʾδ����
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
//���ö�����µ�������
void shiftDown(int* array, int n, int parent) {
	int child = parent * 2 + 1;
	while (child < n) {
		if (child+1<n && array[child] < array[child + 1])
			child++;
		if (array[parent] < array[child])
			Swap(array, parent, child);
	}
}
//������
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
//hoar����ȡ��׼��
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
	//begin �� end ����
	Swap(array, start, begin);
	return begin;
}
//�ڿӷ�
int partion1(int* array, int begin, int end) {
	int key = array[begin];
	int start = begin;
	while (begin < end) {
		//�Ӻ���ǰ��һ���Ȼ�׼ֵС����������һ����
		while (begin < end && array[end] >= key) {
			end--;
		}
		//���
		array[begin] = array[end];
		//��ǰ������һ���Ȼ�׼ֵ���������һ����
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		//���
		array[end] = array[begin];
	}
	//����׼ֵ�����
	array[begin] = key;
	return begin;
}
//ǰ��ָ�뷨
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
//�ݹ�ʵ�ֿ���
void quickSort(int* array, int begin, int end) {
	if (begin >= end)
		return;
	//int keyPos = partion(array, begin, end);
	//int keyPos = partion1(array, begin, end);
	int keyPos = partion2(array, begin, end);
	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}