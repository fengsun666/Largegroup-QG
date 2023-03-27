#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "head.h"
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
void EnQueue(LQ* queue, int temp) {
	N* node = creatNode(temp);
}