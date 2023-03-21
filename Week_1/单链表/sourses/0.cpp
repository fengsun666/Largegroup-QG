#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<stdlib.h>
#include"0.h"
#include <conio.h>

void menu() {
a1:
	Node* L = InitNode();
	printf("				****************				\n");
	printf("				*1.������ͷ�巨*				\n");
	printf("				*2.������β�巨*				\n");
	printf("				***3.ɾ���ڵ�***				\n");
	printf("				***4.��ӡ����***				\n");
	printf("				***5.�жϳɻ�***				\n");
	printf("				***6.�ж��е�***				\n");
	printf("				***7.�˳�����***				\n");
	printf("				****************				\n");
	printf("				***�����룺   **				\n");
	switch (_getch()) {
	case'1': {
	b1:
		int Data;
		system("cls");
		printf("���������ݣ�  \n");
		scanf("%d", &Data);
		InsertHead(L, Data);
		Print(L);
		printf("��a����,�����밴R��r");
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
		}
	}
	case'2': {
	b2:
		int Data;
		system("cls");
		printf("���������ݣ�  \n");
		scanf_s("%d", &Data);
		InsertTail(L, Data);
		Print(L);
		printf("��b����,�����밴R��r");
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
		}
	}
	case'3': {
	b3:
		system("cls");
		int temp;
		Print(L);
		printf("������Ҫɾ��������:  ");
		scanf_s("%d", &temp);
		Delete(L, temp);
		printf("�޸ĺ�����Ϊ  ");
		Print(L);
		printf("��c����,�����밴R��r");
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
		}
	}
	case'4': {
		system("cls");
		Print(L);
		printf("\n");
		printf("��R��r����\n");
		switch (_getch()) {
		case'R':
		case'r': {
			system("cls");
			goto a1;
		}
		}
	}
	case'5': {
		JudgeLoop(JudgeLoop(L));
		Sleep(1000);
		system("cls");
		goto a1;
	}
	case'6': {
		printf("%d", FindMid(L)->data);
		Sleep(1000);
		system("cls");
		goto a1;
	}
	case'7': {

	}
	}
}

Node* InitNode() {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = 0;
	p->next = NULL;
	return p;
}

void InsertHead(Node* L, int data) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	if (L->data == 0) {
		p->next = L->next;
		L->next = p;
		L->data++;
	}
	else {
		p->next = L->next;
		L->next = p;
		L->data++;
	}
}

void Print(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
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
	L->data++;
}

void Delete(Node* L, int data) {
	Node* pre = NULL;
	Node* p = L->next;
	while (pre != NULL) {
		if (L->data == data) {
			pre->next = p->next;
			free(p);
			printf("Success!\n");
		}
		pre = p;
		p = p->next;
	}
	if (p == NULL) printf("Failed!\n");
}

//Ѱ�������е�
Node* FindMid(Node* head)
{
	if (head == NULL) {
		return NULL;
	}
	Node* fast = head;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;    //��ָ��һ��������
		slow = slow->next;          //��ָ��һ����һ��
	}
	return slow;
}

//�жϳɻ�
int JudgeLoop(Node* head)
{
	Node* fast = head->next;
	Node* slow = fast;
	fast = fast->next;
	while (slow != NULL && fast->next != NULL) {
		fast = fast->next->next;    //��ָ��һ��������
		slow = slow->next;          //��ָ��һ����һ��
		if (slow == fast) return TRUE;   //�ɻ�
	}
	return FALSE;  //���ɻ�
}

void JudgeLoop(int judgment) {
	if (judgment) {
		printf("�ɻ���\n");
	}
	else printf("���ɻ���\n");
}