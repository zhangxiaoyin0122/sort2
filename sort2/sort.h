#pragma once

void Swap(int* array, int l, int r);
void bubbleSort(int* array,int n);
void shiftDown(int* array, int n, int parent);
void heapSort(int* array, int n);
//��ȡ��׼��
int partion(int* array, int begin, int end);//hoar��
int partion1(int* array, int begin, int end);//�ڿӷ�
int partion2(int* array, int begin, int end);//˫ָ�뷨

//�ݹ�ʵ�ֿ���
void quickSort(int* array, int begin, int end);