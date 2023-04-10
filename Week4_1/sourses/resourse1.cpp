#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include"head.h"
void InitTree(tree* root) {
	root->data = 0;
	root->left = NULL;
	root->right = NULL;
}
//void InsertTree(tree* root,int a ) {
//	if (!root) {  //�ж�Ϊ��
//		root = (tree*)malloc(sizeof(tree));  //�¿��ٿռ�
//		if (root) {
//			root->data = a;
//			root->left = NULL;
//			root->right = NULL;
//		}
//	}
//	else {  //�ǿ�
//		if (a < root->data) {  //�ݹ����ʹ����ʱ�Զ�����
//			InsertTree(root->left, a);
//		}
//		else {
//			if (a > root->data) {
//				InsertTree(root->right, a);
//			}
//		}
//	}
//}
//void InsertTree(tree* root, int num) {
//	tree* parent = NULL;
//	tree* head = root;
//	tree* p = (tree*)malloc(sizeof(tree));
//	p->data = num;
//	p->left = p->right = NULL;
//	if (head->data == 0) {
//		head->data = num;
//		return;
//	}
//	while (head) {
//		parent = head;
//		if (num < head->data) {
//			if (head->left) {
//				head = head->left;
//			}
//			else {
//				head->left = (tree*)malloc(sizeof(tree));
//				head->left->data = num;
//				head->left->left = head->left->right = NULL;
//				break;
//			}
//		}
//		if (num > head->data) {
//			if (head->right) {
//				head = head->right;
//			}
//			else {
//				head->right = (tree*)malloc(sizeof(tree));
//				head->right->data = num;
//				head->right->left = head->right->right = NULL;
//				break;
//			}
//		}
//	}
//	if (num < parent->data) {
//		parent->left = p;
//	}
//	else {
//		parent->right = p;
//	}
//
//}
void InsertTree(tree*root, int value)
{
	if (root->data == 0) {
		root->data = value;
	}
	if (value == root->data)
	{
		printf("����ʧ��!\n");
		return;
	}
	if (value > root->data)
	{
		if (root->right == NULL)
		{
			tree* p = (tree*)malloc(sizeof(tree));
			root->right = p;
			p->left = p->right = NULL;
			p->data = value;
			printf("����ɹ�!\n");
		}
		else
			InsertTree(root->right, value);
		return;
	}
	if (value < root->data)
	{
		if (root->left == NULL)
		{
			tree* p = (tree*)malloc(sizeof(tree));
			root->left = p;
			p->left = p->right = NULL;
			p->data = value;
			printf("����ɹ�!\n");
		}
		else
			InsertTree(root->left, value);
		return;
	}
}
int TreeEmpty(tree* root) {
	if (root->data == 999) {
		return 0;
	}
	else return 1;
}
N* creatNode(int temp) {
	N* node = (N*)malloc(sizeof(N));
	node->data = temp;
	node->next = NULL;
	return node;
}
LQ* creatLinkQueue() {
	LQ* queue = (LQ*)malloc(sizeof(LQ));
	queue->head = queue->tail = NULL;
	return queue;
}
void porder(tree* root) {
	if (!root) {
		printf("��Ϊ��\n");
	}
	else  {
		printf("%d\t", root->data);
		porder(root->left);
		porder(root->right);
	}
}
void p_order(tree* root) {
	if(!root) {
			printf("��Ϊ��\n");
			return;
	}
	else  {
		tree* node = (tree*)malloc(sizeof(tree));
		int judge = -1;
		tree* p = root;
		while (judge != -1 || p) {  //���ڸ��ڵ�ʱ���ƶ�ָ�벻Ϊ��ʱ
			while (p) {
				printf("%d\t", p->data);
				node[++judge] = *p;  //��node�д����ѱ����ڵ�
				p = p->left;  //�����������ײ�
			}
			if (judge != -1) {
				*p = node[judge];  
				judge--;
				p = p->right;
			}
		}
		free(node);
	}
}
void morder(tree* root) {
	if(!root) {
			printf("��Ϊ��\n");
			return;
	}
	else  {
		morder(root->left);
		printf("%d\t", root->data);
		morder(root->right);
	}

}
void m_order(tree* root) {
	if(!root) {
			printf("��Ϊ��\n");
			return;
	}
	else {
		tree* node = (tree*)malloc(sizeof(tree));
		int judge = -1;
		tree* p = root;
		while (judge != -1 || p) {
			while (p) {
				node[++judge] = *p;
				p = p->left;
			}
			if (judge != -1) {
				*p = node[judge--];
				printf("%d\t", p->data);
				p = p->right;
			}
		}
		free(node);
	}
}
void torder(tree* root) {
	if(!root) {
			printf("��Ϊ��\n");
	}
	else {
		torder(root->left);
		torder(root->right);
		printf("%d\t", root->data);
	}
}
void t_order(tree* root) {
	if(!root) {
		printf("��Ϊ��\n");
		return;
	}
	else {
		tree* node = (tree*)malloc(sizeof(tree));
		int judge = -1;
		tree* p = root;
		while (judge != -1 || p) {
			while (p) {
				node[++judge] = *p;
				p = p->left;
			}
			
		}
		free(node);
	}
}
int Sereach(tree* root, int a) {
	tree* p = root;
	if (!root) {
		return 0;
	}
	else {
		while (p) {
			if (a = p->data) {
				return 1;
			}
			if (a < p->data) {
				p = p->left;
				Sereach(p, a);
			}
			if (a > p->data) {
				p = p->right;
				Sereach(p, a);
			}
		}
		return 0;
	}
}
//int Delete(tree* root, int a) {
//	
//
//}
void LevelOrder(tree* root) {
	if (!root) {

	}
}
void printTree(tree* n)
{
	static int level = -1; //��¼�ǵڼ����
	int i;

	if (NULL == n)
		return;

	level++;
	printTree(n->right);
	level--;

	level++;
	for (i = 0; i < level; i++)
		printf("\t");
	printf("%2d\n", n->data);
	printTree(n->left);
	level--;
}
