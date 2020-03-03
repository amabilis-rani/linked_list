#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct {
	int coef;
	int exp;
	struct listnode *link;
}listnode;
typedef struct {
	int size;
	listnode *head;
	listnode *tail;
}listtype;

listtype* create() { //리스트 헤더 생성함수
	listtype *plist = (listtype *)malloc(sizeof(listtype));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
void insert_list(listtype *plist, int coef, int exp) {
	listnode *temp = (listnode*)malloc(sizeof(listnode));
	if (temp == NULL)
	{
		printf("error");
		exit(1);
	}
	temp->coef = coef;
	temp->exp = exp;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}
void poly_add(listtype*plist1, listtype* plist2, listtype* plist3) {
	listnode *a = plist1->head;
	listnode *b = plist2->head;
	int sum;
	while (a && b) {
		if (a->exp == b->exp) {
			sum = a->coef + b->coef;
			if (sum != 0) {
				insert_list(plist3, sum, a->exp);
			}
			a = a->link;
			b = b->link;
		}
		else if (a->exp > b->exp) {
			insert_list(plist3, a->coef, a->exp);
			a = a->link;
		}
		else {
			insert_list(plist3, b->coef, b->exp);
			b = b->link;
		}
	}
	while (a) {
		insert_list(plist3, a->coef, a->exp);
		a = a->link;
	}
	while (b) {
		insert_list(plist3, b->coef, b->exp);
		b = b->link;
	}
}
void print(listtype *plist) {
	listnode *a = plist->head;
	for (; a; a=a->link) {
		printf("%dx^%d+ ", a->coef, a->exp);
	}
	printf("\n");
}
int main() {
	listtype *plist1 = create();
	listtype *plist2 = create();
	listtype *plist3 = create();
	int coef, exp;
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &coef, &exp);
		insert_list(plist1, coef, exp);
	}
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &coef, &exp);
		insert_list(plist2, coef, exp);
	}
	print(plist1);
	print(plist2);
	poly_add(plist1, plist2, plist3);
	print(plist3);
	free(plist1);
	free(plist2);
	free(plist3);
	return 0;
}
