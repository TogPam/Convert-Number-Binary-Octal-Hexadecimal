#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct Stack{
	struct node *top;
}stack;

node *getNode(int x){
	node *p = (node*)malloc(sizeof(node));
	if(p==NULL) printf("Cannot allocation\n");
	else{
		p->data = x;
		p->next = NULL;
	}
	return p;
}


void initStack(stack &s){
	s.top = NULL;
}

int isEmpty(stack s){
	return s.top == NULL ? 1 : 0;
}

void push(stack &s, int x){
	node *p = getNode(x);
	if(isEmpty(s)) s.top = p;
	else{
		p->next = s.top;
		s.top = p;
	}
}

int pop(stack &s){
	if(isEmpty(s)){
		printf("Stack is empty!\n");
		return 0;
	}
	node *temp = s.top;
	int x = temp->data;
	s.top = temp->next;
	free(temp);
	return x;
}

void top(stack s){
	if(isEmpty(s)==1) return;
	printf("Top: %d\n",s.top->data);
}

void convertBinary(stack &s,int k){
	int amount = 0;
	while(k!=0){
		amount = k % 2;
		push(s,amount);
		k /= 2;
	}
	while(s.top != NULL){
		printf("%d",pop(s));
	}
}

void convertOctal(stack &s, int k){
	int amount = 0;
	while(k!=0){
		amount = k % 8;
		push(s,amount);
		k /= 8;
	}
	while(s.top != NULL){
		printf("%d",pop(s));
	}
}

void convertHexadecimal(stack &s, int k){
	int amount = 0;
	while(k!=0){
		amount = k % 16;
		push(s,amount);
		k /= 16;
	}
	while(s.top != NULL){
		int x = pop(s);
		if(x==10) printf("A");
		else if(x==11) printf("B");
		else if(x==12) printf("C");
		else if(x==13) printf("D");
		else if(x==14) printf("E");
		else if(x==15) printf("F");
		else printf("%d",x);
	}
}

void menu();
int main(){
	stack s;
	initStack(s);
	int c;
	do{
		menu();
		printf("Option: "); scanf("%d",&c);
		switch(c){
			case 1:{
				int k;
				printf("Number: "); scanf("%d",&k);
				convertBinary(s,k);
				getch();
				break;
			}
			case 2:{
				int k;
				printf("Number: "); scanf("%d",&k);
				convertOctal(s,k);
				getch();
				break;
			}
			case 3:{
				int k;
				printf("Number: "); scanf("%d",&k);
				convertHexadecimal(s,k);
				getch();
				break;
			}
		}	
	system("cls");	
	}while(c!=0);
}

void menu(){
	printf("\n1. Binary\n");
	printf("2. Octal\n");
	printf("3. Hexadecimal\n");
	printf("0. Exit\n");
}
