#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"header.h"
void InsertSort(int* arr,int size) {
	int i, j, temp;
	for (i = 1; i < size; i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}
void QuickSort(int* arr, int maxlen, int begin, int end) {
	int i, j;
	if (begin < end) {
		i = begin + 1;
		j = end;
		while (i < j) {
			if (arr[i] > arr[begin]) {
				Exchange(&arr[i], &arr[j]);
				j--;
			}
			else {
				i++;
			}
		}
		if (arr[i] >= arr[begin]) {
			i--;
		}
		Exchange(&arr[begin], &arr[i]);
		QuickSort(arr, maxlen, begin, i);
		QuickSort(arr, maxlen, j, end);
	}
}
void Exchange(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void CountSort(int* arr,int size) {
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] >= max) max = arr[i];
		if (arr[i] <= min) min = arr[i];
	}
	int range = max - min + 1;
	int* b = (int*)calloc(range, sizeof(int));
	if (!b) { return; }
	for (int i = 0; i < size; i++) {
		b[arr[i] - min] += 1;
	}
	int j = 0;
	for (int i = 0; i < range; i++) {
		while (b[i]--) {
			arr[j++] = i + min;
		}
	}
	free(b);
	b = NULL;
}
void Merge(int* arr, int start, int mid, int end, int size) {
	int* arr1 = (int*)calloc(size , sizeof(int));
	if (!arr1 || !arr) { return; }
	int k = 0;
	int i = start; int j = mid + 1;
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			arr1[k++] = arr[i++];
		}
		else {
			arr1[k++] = arr[j++];
		}
	}
	if (i == mid + 1) {
		while (j <= end) {
			arr1[k++] = arr[j++];
		}
	}
	if (j == end + 1) {
		while (i <= mid) {
			arr1[k++] = arr[i++];
		}
	}
	for (j = 0, i = start; j < k; j++, i++) {
		arr[i] = arr1[j];
	}
	free(arr1);
	return;
}
void MergeSort(int* arr, int start, int end,int size) {
	if (start >= end) return;
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid, size);
	MergeSort(arr, mid + 1, end, size);
	Merge(arr, start, mid, end, size);
}
int FindMax(int* arr, int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		max = max >= arr[i] ? max : arr[i];
	}
	return max;
}
int FindMin(int* arr, int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		min = min <= arr[i] ? min : arr[i];
	}
	return min;
}

	
void RandixCountSort(int* arr, int size) {
	if (!size) { return; }
	int *b[10], cnt[10];
	for (int i = 0; i < 10; ++i) {
		b[i] = (int*)malloc(size * sizeof(int));
		cnt[i] = 0;
		if (!b[i]) { return; }
	}
	int max = arr[0]; for (int i = 1; i < size; ++i) { max = (max > arr[i] ? max : arr[i]); }
	int cur = 1;
	while (cur <= max) {
		for (int i = 0; i < size; ++i) {
			const int digit = arr[i] / cur % 10;
			b[digit][cnt[digit]++] = arr[i];
		}
		int pos = 0;
		for (int i = 0; i < 10; ++i) {
			for(int j = 0; j < cnt[i]; ++j) {
				arr[pos++] = b[i][j] ;
			}
			cnt[i] = 0;
		}
		cur *= 10;
	}
}
int Find_k_min(int* arr, int begin, int end, int k) {
	int i, j;
	if (begin < end) {
		i = begin + 1;
		j = end;
		while (i < j) {
			if (arr[i] > arr[begin]) {
				Exchange(&arr[i], &arr[j]);
				j--;
			}
			else {
				i++;
			}
		}
		if (arr[i] >= arr[begin]) {
			i--;
		}
	}
	Exchange(&arr[begin], &arr[i]);
	int tempbegin, tempend;
	if (i < k - 1) {
		tempbegin = begin;
		tempend = i;
		Find_k_min(arr, tempbegin, tempend, k);
	}
	if (i > k - 1) {
		tempbegin = i;
		tempend = end;
		Find_k_min(arr, tempbegin, tempend, k);
	}
	if (i == k - 1) {
		return k;
	}
}
void ColorSort(int* arr, int size) {
	int index1 = 0;
	int cur = 0;
	int index2 = size - 1;
	while (cur <= index2) {
		if (arr[cur] == 0) {
			Exchange(arr + cur, arr + index1);
			index1++;
			cur++;
		}
		else if (arr[cur] == 2) {
			Exchange(arr + cur, arr + index2);
			index2--;
		}
		else cur++;
	}
}
int* OpenFile(int parameter) {
	if (parameter == 1) {
		static int a[20] = { 6,99,2,5,36,484,4841,63456,0,54,484,1184,2,114514,300,100,100,16,84,3 };
		return a;
	}
	if (parameter == 2) {
		static int a[10000] = { 0 };
		int i = 0;
		FILE* fp = fopen("10000.txt", "r");
		while (fgetc(fp) != '\0' || fgetc(fp) != EOF) {
			fscanf(fp, "%d", &a[i]);
			i++;
		}
		return a;
	}
	if (parameter == 3) {
		static int a[50000] = { 0 };
		int i = 0;
		FILE* fp = fopen("50000.txt", "r");
		while (fgetc(fp) != '\0' || fgetc(fp) != EOF) {
			fscanf(fp, "%d", &a[i]);
			i++;
		}
		return a;
	}
	if (parameter == 4) {
		static int a[200000] = { 0 };
		int i = 0;
		FILE* fp = fopen("200000.txt", "r");
		while (fgetc(fp) != '\0' || fgetc(fp) != EOF) {
			fscanf(fp, "%d", &a[i]);
			i++;
		}
		return a;
	}
	if (parameter == 5) {
		static int a[100] = { 0 };
		long timesum = 0;
		for (long long i = 0; i < 100000; i++) {
			for (long long j = 100 * i; j < 100 * (i + 1); j++) {

			}
		}
	}
}
void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}