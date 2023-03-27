#pragma once
typedef struct StackNode {
	double data;
	struct StackNode* next;
}Node;

typedef struct LinkStack {
	Node* top;
	int count;
}Stack;
void menu();
void initStack(Stack* s);
int isEmptyStack(Stack* s);
void printEmpty(int parameter);
Node* getTopStack(Stack* s);
void clearStack(Stack* s);
void pushStack(Stack* s, double temp);
double popStack(Stack* s);
int isNumber(char str);
int isSign(char str);
int priority(char sign);