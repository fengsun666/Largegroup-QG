#define TRUE 1
#define FALSE 0
#include<Windows.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
Node* InitNode();
void InsertHead(Node* L, int data);
void InsertTail(Node* L, int data);
void Print(Node* L);
void Delete(Node* L, int data);
Node* FindMid(Node* head);
int JudgeLoop(Node* head);
void JudgeLoop(int judgment);
void menu();
