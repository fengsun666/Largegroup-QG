typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;
Node* InitNode();
void menu();
void InsertHead(Node* L, int data);
void InsertTail(Node* L, int data);
void Print(Node* L);
void Delete(Node* L, int data);
void Attention();
