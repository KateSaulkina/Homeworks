#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "list.c"

#define PrintList 1
#define makeList 2
#define addHead 3
#define addEnd 4
#define addAfter 5
#define DeleteNode 6
#define CleanList 7
#define CheckCycle 8
#define Exit 9

int main()
{

	struct List* list = NULL;
	int choice = -1;
	size_t value;
	size_t after;
	int ex = 1;

	while (ex) {
		printf("\nPrint List - 1\n");
		printf("Create List - 2\n");
		printf("Add Head - 3\n");
		printf("Add Tail - 4\n");
		printf("Add After - 5\n");
		printf("Delete Node - 6\n");
		printf("Clean List - 7\n");
		printf("Check Cycle - 8\n");
		printf("Exit - 9\n");
		printf("Enter your act: ");
		printf("\n\n");
		scanf("%d", &choice);
		switch (choice) {
            case PrintList:
				if (list != NULL) {
					printList(list);
					printf("\n");
				}
				else {
					printf("List is empty\n");
				}
				break;
			case makeList:
				list = createList();
				printf("List was created\n");
				break;
			case addHead:
				if (list != NULL) {
					printf("Your value: ");
					scanf("%u", &value);
					insertToBegin(list, createNode(value));
				}
				else {
					printf("List is empty\n");
				}
				break;
			case addEnd:
				if (list != NULL) {
					printf("Your value: ");
					scanf("%u", &value);
					insertAfterEl(list, list -> end, createNode(value));
				}
				else {
					printf("List is empty\n");
				}
				break;
			case addAfter:
				if (list != NULL) {
					printf("After element: ");
					scanf("%u", &after);
					printf("Add value: ");
					scanf("%u", &value);
					insertAfterEl(list, getN(list, after), createNode(value));
				}
				else {
					printf("List is empty\n");
				}
				break;
			case DeleteNode:
				if (list != NULL) {
					printf("Your value: ");
					scanf("%u", &value);
					deleteNode(list, getN(list, value));
				}
				else {
					printf("List is empty\n");
				}
				break;
			case CleanList:
				if (list != NULL) {
					clearList(list);
					printf("list was cleaned\n");
				}
				else {
					printf("List is empty\n");
				}
				break;

            case CheckCycle:
                if (list != NULL) {
					if (checkCycle(list)) {
                        printf("You have cycle\n");
					} else {
                        printf("You have not cycle\n");
					}
				}
				else {
					printf("List is empty\n");
				}
				break;

            case Exit:
                free(list);
                ex = 0;
                break;

			default:
				printf("No the option\n");
				break;
		}
	}
	return 0;
}
