#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct Node {
	int data;
	struct Node* next;
};

struct List {
	struct Node* head;
	struct Node* end;
	size_t length;
};

struct List* createList();
struct Node* createNode(int val);
void insertToBegin(struct List* list, struct Node* node);
void insertAfterEl(struct List* list, struct Node* after, struct Node* newNode);
struct Node* getN(struct List* list, size_t n);
void deleteNode(struct List* list, struct Node* toDelete);
void clearList(struct List* list);
void printList(struct List* list);
void printNode (struct List* list, size_t n);

#endif // LIST_H_INCLUDED
