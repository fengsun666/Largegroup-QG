#pragma once
typedef struct BinaryTree {
	int data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}tree;
typedef struct Node {
	int data;
	Node* next;
}N;
typedef struct LinkQueue {
	N* head;
	N* tail;
}LQ;
N* creatNode(int temp);
LQ* creatLinkQueue();
void InitTree(tree* root);  //��ʼ����
void InsertTree(tree* root, int value);  //����������Զ�����
int TreeEmpty(tree* root);  //�ж����Ƿ�Ϊ��
void menu();
void porder(tree* root);  //����������ݹ飩
void p_order(tree* root);  //����������ǵݹ飩
void morder(tree* root);  //����������ݹ飩
void m_order(tree* root);  //����������ǵݹ飩
void torder(tree* root);  //����������ݹ飩
void t_order(tree* root);  //�����������ǵݹ飩
int Sereach(tree* root, int a);  //���Ҳ���
int Delete(tree* root, int a);  //ɾ���ڵ����
void LevelOrder(tree* root);
void printTree(tree* n);
