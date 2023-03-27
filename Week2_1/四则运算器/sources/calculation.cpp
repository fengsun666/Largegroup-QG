#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include"0.h"
int main() {
	int i;
	int tempData = 0;
	char arr[1000] = { 0 };
	Stack num_stack;
	Stack sign_stack;
	initStack(&num_stack);
	initStack(&sign_stack);
	menu();
	switch (_getch()) {
	case'1': {
		printf("请输入中缀表达式：\n");
		scanf("%s", arr);
		i = 0;
		while (arr[i] != '\0'||isEmptyStack(&sign_stack)!=1) {
			Node* n1 = (Node*)malloc(sizeof(Node));
			if (isNumber(arr[i])) {
				tempData = tempData * 10 + arr[i] - '0';
				i++;
				if (isNumber(arr[i]) == 0) {
					Node* n2 = (Node*)malloc(sizeof(Node));
					pushStack(&num_stack, tempData);
					tempData = 0;
				}
			}
			else {
				if (isEmptyStack(&sign_stack) || priority(arr[i]) > priority(getTopStack(&sign_stack)->data) || (getTopStack(&sign_stack)->data == '(' && arr[i] != ')' && arr[i] != '='))
				{
					pushStack(&sign_stack, arr[i]);
					i++;
					continue;
				}
				if (getTopStack(&sign_stack)->data == '(' && arr[i] == ')')
				{
					popStack(&sign_stack);
					i++;
					continue;
				}
				if (priority(arr[i]) <= priority(getTopStack(&sign_stack)->data) || arr[i] == ')' && getTopStack(&sign_stack)->data != '(' || arr[i] == '=' && isEmptyStack(&sign_stack) == 0)
				{
					switch ((char)popStack(&sign_stack))
					{

						double num1, num2;
					case '+':
					{
						num1 = popStack(&num_stack);
						num2 = popStack(&num_stack);
						n1->data = num1 + num2;
						pushStack(&num_stack, n1->data);
						break;
					}
					case '-':
					{
						num1 = popStack(&num_stack);
						num2 = popStack(&num_stack);
						n1->data = num2 - num1;
						pushStack(&num_stack, n1->data);
						break;
					}
					case '*':
					{
						num1 = popStack(&num_stack);
						num2 = popStack(&num_stack);
						n1->data = num1 * num2;
						pushStack(&num_stack, n1->data);
						break;
					}
					case '/':
					{
						num1 = popStack(&num_stack);
						num2 = popStack(&num_stack);
						n1->data = num2 / num1;
						pushStack(&num_stack, n1->data);
						break;
					}
					default:
						break;
					}
				}
			}
		}
		printf("%lf\n", popStack(&num_stack));
	}
	case'2': {

	}
	}
}
	

