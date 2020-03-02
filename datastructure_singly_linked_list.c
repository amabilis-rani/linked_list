#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

#define MAX_LIST_SIZE 100
typedef int element;
typedef struct {
	element data;
	struct listnode *link;
}listnode;
listnode* insert_first(listnode *head, element item) {//head변경
	listnode *p = (listnode*)malloc(sizeof(listnode));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}
listnode* insert(listnode *head, element item, int pos) { //node 중간 삽입
	listnode *p = (listnode*)malloc(sizeof(listnode));
	listnode *pre = head;
	for (int i = 0; i < (pos -1); i++) {
		pre = pre->link;
	}
	p->data = item;
	p->link = pre->link;
	pre->link = p;
	return head;
}
listnode* delete_first(listnode *head) {//head 삭제
	listnode *removed = head;
	head = removed->link;
	free(removed);
	return head;
}
listnode* delete(listnode *head, int pos) {//node 중간 삭제 
	listnode *pre = head;
	listnode *removed = NULL;
	for (int i = 0; i < (pos-1); i++) {
		pre = pre->link;
	}
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
element get_entry(listnode *head, int pos) {
	listnode *p = head;
	for (int i = 0; i < pos; i++) {
		p = p->link;
	}
	return p->data;
}
listnode *search_list(listnode *head, element item) {//특정한 값을 탐색하는 함수
	for (listnode *p = head; p != NULL; p = p->link) {
		if (p->data == item) {
			return p;
		}
	}
	return NULL;
}
listnode *concat_list(listnode *head1, listnode *head2) {//두 리스트 연결 함수
	listnode *p = head1;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = head2;
	return head1;
}
listnode *reverse(listnode *head) {//리스트를 역순으로 만드는 함수
	listnode *pre , *p = NULL, *pro = head;
	while(pro != NULL) {
		pre = p;
		p = pro;
		pro = p->link;
		p->link = pre;
	}
	return p;
}
void print_list (listnode *head) {
	for (listnode *p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}
int main() {
	listnode *head1 = NULL, *head2 = NULL, *head3 = NULL;
	head1 = insert_first(head1, 10);
	print_list(head1);
	head1 = insert_first(head1, 20);
	print_list(head1);
	head1 = insert_first(head1, 30);
	print_list(head1);
	
	head1 = reverse(head1);
	print_list(head1);
	return 0;
}
