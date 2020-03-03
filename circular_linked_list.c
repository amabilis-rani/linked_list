#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


typedef struct listnode{
	char data[100];
	struct listnode *link;
}listnode;
listnode* insert_first(listnode *head, char name[]) {
	listnode *node = (listnode *)malloc(sizeof(listnode));
	strcpy(node->data,name);
	if (head == NULL) {
		head = node; 
		head->link = node;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}
void print(listnode *p) {
	printf("이번 순서는 : %s\n", p->data);
}
int main() {
	listnode *head = NULL, *p;

	head = insert_first(head, "anna");
	head = insert_first(head, "elsa");
	head = insert_first(head, "disney");
	p = head;
	for (int i = 0; i < 10; i++) {
		print(p);
		p = p->link;
	}
	return 0;
}
