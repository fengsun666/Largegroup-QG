	#define _CRT_SECURE_NO_WARNINGS
	#include <conio.h>
	#include"header.h"
	#include<stdio.h>
	#include<stdlib.h>
    #include<Windows.h>
    #include<time.h>
void menu1() {
	printf("			********************			\n");
	printf("			******1.����********			\n");
	printf("			******2.�鲢********[��bug]			\n");
	printf("			******3.����********			\n");
	printf("			******4.����********			\n");
	printf("			******5.����********			\n");
	printf("			******6.��ɫ********			\n");
	printf("			*****7.�ҵ�kС******[��bug]			\n");
	printf("			******8.�˳�********			\n");
	printf("			********************			\n");
	printf("			�����룺			\n");
	switch (_getch())
	{
	case'1': {
		system("cls");
		clock_t start = clock();
		InsertSort(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		clock_t diff = clock() - start;
		print(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		printf("\n");
		printf("����ʱ%d ms\n", diff);
	}
	case'2': {
		system("cls");
		clock_t start = clock();
		MergeSort(OpenFile(menu2()), 0, sizeof(OpenFile(menu2())) / sizeof(int) - 1, sizeof(OpenFile(menu2())) / sizeof(int));
		clock_t diff = clock() - start;
		print(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		printf("\n");
		printf("����ʱ%d ms\n", diff);
	}
	case'3': {
		system("cls");
		clock_t start = clock();
		QuickSort(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int), 0, sizeof(OpenFile(menu2())) / sizeof(int) - 1);
		clock_t diff = clock() - start;
		print(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		printf("\n");
		printf("����ʱ%d ms\n", diff);
	}
	case'4': {
		system("cls");
		clock_t start = clock();
		CountSort(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		clock_t diff = clock() - start;
		print(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		printf("\n");
		printf("����ʱ%d ms\n", diff);
	}
	case'5': {
		system("cls");
		clock_t start = clock();
		RandixCountSort(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		clock_t diff = clock() - start;
		print(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		printf("\n");
		printf("����ʱ%d ms\n", diff);
	}
	case'6': {
		system("cls");
		clock_t start = clock();
		ColorSort(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		clock_t diff = clock() - start;
		print(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		printf("\n");
		printf("����ʱ%d ms\n", diff);
	}
	case'7': {
		system("cls");
		int k;
		printf("������k��ֵ\n");
		scanf("%d", &k);
		clock_t start = clock();
		Find_k_min(OpenFile(menu2()), 0, sizeof(OpenFile(menu2())) / sizeof(int) - 1, k);
		clock_t diff = clock() - start;
		print(OpenFile(menu2()), sizeof(OpenFile(menu2())) / sizeof(int));
		printf("\n");
		printf("����ʱ%d ms\n", diff);
	}
	case'8': {
		break;
	}
	}
}
int menu2() {
	printf("			****(���ź�Ϊ���ݴ�С)****			\n");
	printf("			**************************			\n");
	printf("			***1.����(20)*************			\n");
	printf("			***2.���һ(10000)********			\n");
	printf("			***3.��ζ�(50000)********			\n");
	printf("			***4.�����(200000)*******			\n");
	printf("			***5.�����(100*100k)*****			\n");
	printf("			***6.�˳�*****************			\n");
	printf("			�����룺			\n");
	switch (_getch())
	{
	case'1': {
		return 1;
	}
	case'2': {
		return 2;
	}
	case'3': {
		return 3;
	}
	case'4': {
		return 4;
	}
	case'5': {
		return 5;
	}
	case'6': {
		return 6;
	}
	}
}