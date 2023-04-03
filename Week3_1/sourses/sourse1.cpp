#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <conio.h>
#include"header.h"
#include<time.h>
//测试数据
//int main() {
//	int a[20] = { 6,99,2,5,36,484,4841,63456,0,54,484,1184,2,114514,300,100,100,16,84,3 };
//	int b[10] = { 0,2,2,1,2,0,1,2,0,0 };
//	int c[7] = { 5,2,8,4,3,7,6, };
//	InsertSort(a, sizeof(a) / sizeof(int));
//	QuickSort(a, sizeof(a)/sizeof(int), 0, sizeof(a) / sizeof(int)-1);
//	CountSort(a, sizeof(a) / sizeof(int));
//	MergeSort(a, FindMin(a, sizeof(a) / sizeof(int)), FindMax(a, sizeof(a) / sizeof(int)), sizeof(a) / sizeof(int));
//	RandixCountSort(a, sizeof(a) / sizeof(int));
//	ColorSort(b, sizeof(b) / sizeof(int));
//	printf("%d\n", c[Find_k_min(c, 0, sizeof(a) / sizeof(int) - 1, 3)]);
//	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
//		printf("%d ", a[i]);
//	}
//	for (int i = 0; i < sizeof(c) / sizeof(int); i++) {
//		printf("%d ", c[i]);
//	}
//	for (int i = 0; i < sizeof(b) / sizeof(int); i++) {
//		printf("%d ", b[i]);
//	}
//}
// 
// 

int main() {
	menu1();

}

//录入随机数据
//int main() {
//	srand(time(NULL));
//	FILE* fpw = fopen("100 x 100k.txt", "w");
//	if (fpw == NULL) {
//		return 0;
//	}
//	for (long long i = 0; i < 10000000; i++) {
//		fprintf(fpw, "%d ", rand() % 100001);
//	}
//	fclose(fpw);
//}

