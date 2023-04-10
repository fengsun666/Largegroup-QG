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
void InitTree(tree* root);  //初始化树
void InsertTree(tree* root, int value);  //插入操作（自动排序）
int TreeEmpty(tree* root);  //判断树是否为空
void menu();
void porder(tree* root);  //先序遍历（递归）
void p_order(tree* root);  //先序遍历（非递归）
void morder(tree* root);  //中序遍历（递归）
void m_order(tree* root);  //中序遍历（非递归）
void torder(tree* root);  //后序遍历（递归）
void t_order(tree* root);  //后续遍历（非递归）
int Sereach(tree* root, int a);  //查找操作
int Delete(tree* root, int a);  //删除节点操作
void LevelOrder(tree* root);
void printTree(tree* n);
