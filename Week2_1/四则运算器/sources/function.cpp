#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include"0.h"
void menu() {
	printf("			*****四则计算器*****			\n");
	printf("			*****1.进入计算*****			\n");
	printf("			*****2.退出界面*****			\n");
	printf("			********************			\n");
	printf("				请输入序号:\n");
}
void initStack(Stack* s) {
	if(s) {
		s->count = 0;
		s->top = NULL;
	}
}
int isEmptyStack(Stack* s) {
	return s->count == 0 ? 1 : 0;
}
void printEmpty(int parameter) {
	if (parameter) printf("Is Empty!\n");
	else printf("No Empty!\n");
}
Node* getTopStack(Stack* s) {
	if (s == NULL || s->top == NULL) return NULL;
	return s->top;
}
void clearStack(Stack* s) {
	Node* n;
	while (s->top) {
		n = s->top->next;
		free(s->top);
		s->top = n;
	}
	s->count = 0;
}
void pushStack(Stack* s, double temp) {
	if (s == NULL) {
		return;
	}
	Node* n = (Node*)malloc(sizeof(Node));
	n->next = NULL;
	n->data = temp;
	n->next = s->top;
	s->top = n;
	s->count++;
}
double popStack(Stack* s) {
	double Data = 0;
	if (s == NULL || s->count == 0) return 0;
	Data = s->top->data;
	s->count--;
	Node* n = s->top->next;
	free(s->top);
	s->top = n;
	return Data;
}
int isNumber(char str) {
	if (str >= '0' && str <= '9') return 1;
	return 0;
}
int isSign(char str) {
	if (str == '+' || str == '-' || str == '*' || str == '/' ) return 1;
	return 0;

}
int priority(char sign)
{
	switch (sign)
	{
	case '(':
		return 3;
	case '/':
	case '*':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}