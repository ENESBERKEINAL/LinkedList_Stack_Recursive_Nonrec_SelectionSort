#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct s {
	int item;
	struct s *next;
}STACK;

STACK *sp = NULL;

void List(STACK *tp) {                 
	while (tp) {
		printf("-->%d ", tp->item);
		tp = tp->next;
	}
	printf("\n");
}

void push(int item) {
	STACK *p;
	p = (STACK *)malloc(sizeof(STACK));
	if (p == NULL) {
		printf("NOT ENOUGH SPACE\n");
	}
	else {
		p->item = item;
		p->next = sp;
		sp = p;
	}
}

//int size() {
//	STACK *p;
//	int i = 0;
//	p = sp;
//	while (p) {
//		i++;
//		p->next = sp;
//	}
//	return i;
//}

int RecursiveSort(STACK *kp) {
	STACK *tp = kp;

	if (kp == NULL)         //base case
		return 0;
	STACK *min = kp;
	STACK *r = kp->next;

	while (r) {
		if (min->item > r->item)
			min = r;

		r = r->next;
	}
	int x = kp->item;				//SWAP FUNC
	kp->item = min->item;			//SWAP FUNC
	min->item = x;					//SWAP FUNC
	printf("%d,", kp->item);		//PRINT SORTED STACK
	kp = tp->next;


	return RecursiveSort(kp);
	printf("\n");
}

void NonRecursiveSort(STACK *kp) {
	while (kp) {
		STACK *min = kp;
		STACK *r = kp->next;

		while (r) {
			if (min->item > r->item)
				min = r;                  //find min and update min

			r = r->next;
		}
		int x = kp->item;				//SWAP FUNC
		kp->item = min->item;			//SWAP FUNC
		min->item = x;					//SWAP FUNC
		printf("%d,", kp->item);		//PRINT SORTED STACK
		kp = kp->next;					//SWAP FUNC
	}
	printf("\n");
}

void main() {
	int choice;
	bool exit = false;
	while (!exit) {
		printf("\n  1--For add new number        \n  2--For recursive sort       \n  3--For nonrecursive sort\n  4--For listing\n  -1--For exit\n");
		scanf("%d", &choice);
		switch (choice) {

		case 1:
			int item;
			printf("Your number:  ");
			scanf("%d", &item);
			push(item);
			break;
		case 2:
			RecursiveSort(sp);
			break;
		case 3:
			NonRecursiveSort(sp);
			break;
		case 4:
			List(sp);
			break;
		case -1:
			exit = true;
			break;
		default:
			printf("WRONG NUMBER");
			break;
		}
	}
	while (sp) {
		STACK *p = sp;
		sp = sp->next;
		free(p);
	}
}