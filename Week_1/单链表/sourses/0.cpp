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
	printf("				*1.单链表头插法*				\n");
	printf("				*2.单链表尾插法*				\n");
	printf("				***3.删除节点***				\n");
	printf("				***4.打印链表***				\n");
	printf("				***5.判断成环***				\n");
	printf("				***6.判断中点***				\n");
	printf("				***7.退出界面***				\n");
	printf("				****************				\n");
	printf("				***请输入：   **				\n");
	switch (_getch()) {
	case'1': {
	b1:
		int Data;
		system("cls");
		printf("请输入数据：  \n");
		scanf("%d", &Data);
		InsertHead(L, Data);
		Print(L);
		printf("按a继续,返回请按R或r");
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
		printf("请输入数据：  \n");
		scanf_s("%d", &Data);
		InsertTail(L, Data);
		Print(L);
		printf("按b继续,返回请按R或r");
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
		printf("请输入要删除的数据:  ");
		scanf_s("%d", &temp);
		Delete(L, temp);
		printf("修改后链表为  ");
		Print(L);
		printf("按c继续,返回请按R或r");
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
		printf("按R或r返回\n");
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

//寻找链表中点
Node* FindMid(Node* head)
{
	if (head == NULL) {
		return NULL;
	}
	Node* fast = head;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;    //快指针一次走两步
		slow = slow->next;          //慢指针一次走一步
	}
	return slow;
}

//判断成环
int JudgeLoop(Node* head)
{
	Node* fast = head->next;
	Node* slow = fast;
	fast = fast->next;
	while (slow != NULL && fast->next != NULL) {
		fast = fast->next->next;    //快指针一次走两步
		slow = slow->next;          //慢指针一次走一步
		if (slow == fast) return TRUE;   //成环
	}
	return FALSE;  //不成环
}

void JudgeLoop(int judgment) {
	if (judgment) {
		printf("成环！\n");
	}
	else printf("不成环！\n");
}