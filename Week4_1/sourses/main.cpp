#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"head.h"
int main() {
a1:
	menu();
	int a;
	tree* root = (tree*)malloc(sizeof(tree));
	InitTree(root);
	scanf("%d", &a);
	switch (a)
	{
	case 1: {
	a2:
		int c;
		printf("����������ֵ��(����999����)��\n");
		scanf("%d", &c);
		if (c == 999) {
			system("cls");
			goto a1;
		}
		InsertTree(root, c);
		printTree(root);
		if (c != 999) {
			goto a2;
		}
	}
	case 2 : {
		printTree(root);
		printf("\n");
		porder(root);
	}
	case 3 : {
		printTree(root);
		printf("\n");
		morder(root);
	}
	case 4 : {
		printTree(root);
		printf("\n");
		torder(root);
	}
	case 5 : {
		printTree(root);
		printf("\n");
		p_order(root);
	}
	case 6 : {
		printTree(root);
		printf("\n");
		m_order(root);
	}
	case 7 : {
		printTree(root);
		printf("\n");
		t_order(root);
	}
	case 8 : {
		int b;
		printf("������ҪѰ�ҵ�ֵ��\n");
		scanf("%d", &b);
		if (Sereach(root, b)) {
			printf("���д��ڸ�ֵ\n");
		}
		else {
			printf("���в����ڸ�ֵ\n");
		}
	}
	case 9 : {
		int b;
		printf("������Ҫɾ����ֵ��\n");
		scanf("%d", &b);
	}
	case 10 : {
		printTree(root);

	}
	case 11 : {
		printTree(root);
	}
	case 12 : {
		break;
	}
	}
}