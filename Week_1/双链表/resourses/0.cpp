#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"0.h"
#include <conio.h>
#include<Windows.h>
void menu() {
	Node* L = InitNode();
	int Data;
a1:
	printf("				****************				\n");
	printf("				*1.��ʼ��˫����*				\n");
	printf("				*2.˫����ͷ�巨*				\n");
	printf("				*3.˫����β�巨*				\n");
	printf("				***4.ɾ���ڵ�***				\n");
	printf("				***5.��ӡ����***				\n");
	printf("				***6.�˳�����***				\n");
	printf("				****************				\n");
	printf("				***�����룺   **				\n");
	switch (_getch()) {
	case'1': {
		Node* L = InitNode();
		printf("��ʼ����ɣ�\n");
		Sleep(1000);
		system("cls");
		goto a1;
	}
	case'2': {
	b1:
		system("cls");
		printf("���������ݣ�  \n");
		scanf_s("%d", &Data);
		InsertHead(L, Data);
		Print(L);
		printf("�����������,�����밴R��r");
		switch (_getch()) {
		case'A':
		case'a': {
			goto b1;
		}
		case'R':
		case'r': {
			system("cls");
			goto a1;
		}
		default: {
			system("cls");
			Attention();
			goto b1;
		}
		}
	}
	case'3': {
	b2:
		system("cls");
		printf("���������ݣ�  \n");
		scanf_s("%d", &Data);
		InsertTail(L, Data);
		Print(L);
		printf("�����������,�����밴R��r");
		switch (_getch()) {
		case'B':
		case'b': {
			goto b2;
		}
		case'R':
		case'r': {
			system("cls");
			goto a1;
		}
		default: {
			system("cls");
			Attention();
			goto b2;
		}

		}
	}
	case'4': {
	b3:
		system("cls");
		int temp;
		Print(L);
		printf("������Ҫɾ��������:  ");
		scanf_s("%d",&temp);
		Delete(L, temp);
		printf("�޸ĺ�����Ϊ  ");
		Print(L);
		printf("�����������,�����밴R��r");
		switch (_getch()) {
		case'C':
		case'c': {
			goto b3;
		}
		case'R':
		case'r': {
			system("cls");
			goto a1;
		}
		default: {
			system("cls");
			Attention();
			goto b3;
		}
		}
	}
	case'5': {
		Print(L);
		Sleep(1000);
		system("cls");
		goto a1;
	}
	case'6': {
		break;
	}
	default: {
		system("cls");
		Attention();
		goto a1;
	}
	}
}

Node* InitNode() {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = 0;
	p->pre = NULL;
	p->next = NULL;
	return p;
}

void InsertHead(Node* L, int data) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	if (L->data == 0) {
		p->next = L->next;
		p->pre = L;
		L->next = p;
		L->data++;
	}
	else {
		p->pre = L;
		p->next = L->next;
		L->next->pre = p;
		L->next = p;
		L->data++;
	}
}

void InsertTail(Node* L, int data) {
	Node* p1 = L;
	Node* p2 = (Node*)malloc(sizeof(Node));
	p2->data = data;
	while (p1->next != NULL) {
		p1 = p1->next;
	}
	p2->next = p1->next;
	p1->next = p2;
	p2->pre = p1;
	L->data++;
}

void Print(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void Delete(Node* L, int data) {
	Node* p = L->next;
	while (p != NULL) {
		if (p->data == data) {
			p->pre->next = p->next;
			p->next->pre = p->pre;
			free(p);
			printf("Success!\n");
		}
		p = p->next;
	}
	if (p == NULL) printf("Failed!\n");
}

void Attention() {
	printf("�������\n");
}