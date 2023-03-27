#pragma once
#include <stdio.h>
#include <stdlib.h>
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
void DestroyQueue(LQ* p);
void EnQueue(LQ* queue, int temp);
void DeQueue
void ClearQueue

